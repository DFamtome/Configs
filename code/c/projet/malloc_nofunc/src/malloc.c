#include "malloc.h"

APages start = { 0 };

void *set_page(unsigned int len)
{
    void *result;
    if (len == 0
        || (result = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE,
                          MAP_PRIVATE | MAP_ANONYMOUS, -1, 0))
            == MAP_FAILED)
    {
        return NULL;
    }

    struct MHeader *header = result;

    header->is_free = 1;
    header->size = len - sizeof(struct MHeader);
    header->next = header->prev = NULL;

    start.pages[start.nb_alloc] = result;

    start.nb_alloc++;

    return result;
}

void reorga_page(void *acc, unsigned int len)
{
    char *pos = acc;
    void *v_next = pos + sizeof(struct MHeader) + len;

    struct MHeader *acc_h = acc;
    struct MHeader *next = v_next;

    if (acc_h->size == len)
    {
        return;
    }

    next->is_free = 1;
    next->size = acc_h->size - len - sizeof(struct MHeader);
    next->next = acc_h->next;
    next->prev = acc;

    *acc_h = (struct MHeader){ 0, len, next, acc_h->prev };
}

void *find_space(size_t size)
{
    size_t real_size = (size & ~(0xf)) + (0x10 * !!(size & 0xf));
    void *result = NULL;

    for (size_t i = 0; i < start.nb_alloc && !result; i++)
    {
        struct MHeader *block = start.pages[i];

        for (; !block->is_free
             || (block->size < real_size
                 && block->size - real_size < sizeof(struct MHeader));
             block = block->next)
            ;

        if (block->size == real_size && block->is_free)
        {
            result = block + 1;
        }
        else if (block->size >= real_size + sizeof(struct MHeader))
        {
            void *VBlock = block;
            reorga_page(VBlock, real_size);
            result = block + 1;
        }
    }

    return result;
}

void *real_malloc(size_t size)
{
    size_t real_size = (size & ~(0xf)) + (0x10 * !!(size & 0xf));
    if (size == 0)
    {
        return NULL;
    }

    // If 7/8 of the page will be taken on this allocation -> creat a new page
    if (real_size > PAGE_SIZE - (PAGE_SIZE >> 3))
    {
        struct MHeader *res = set_page(real_size + sizeof(struct MHeader));
        res->is_free = 0;
        return res + 1;
    }

    struct MHeader *result;
    if ((result = find_space(real_size)))
    {
        return result;
    }

    if (start.nb_alloc < NB_PAGES && (result = set_page(PAGE_SIZE)))
    {
        reorga_page(result, real_size);
        return result + 1;
    }

    if ((result = set_page(real_size)))
    {
        result->is_free = 0;
        return result + 1;
    }

    return result;
}

__attribute__((visibility("default"))) void *malloc(size_t size)
{
    return real_malloc(size);
}

__attribute__((visibility("default"))) void free(void *ptr)
{
    if (!ptr)
    {
        return;
    }

    struct MHeader *header = ptr;
    header--;

    header->is_free = 1;

    if (header->next && header->next->is_free)
    {
        header->size += header->next->size + sizeof(struct MHeader);
        header->next = header->next->next;
    }

    if (header->prev && header->prev->is_free)
    {
        header->prev->size += header->size + sizeof(struct MHeader);
        header->prev->next = header->next;
    }

    if (!header->next && !header->prev)
    {
        void *s_page = header;
        size_t i = 0;
        for (; i < start.nb_alloc && s_page != start.pages[i]; i++)
            ;

        if (i < start.nb_alloc)
        {
            for (; i < start.nb_alloc - 1; i++)
            {
                start.pages[i] = start.pages[i + 1];
            }

            start.pages[--start.nb_alloc] = NULL;
        }
        munmap(header, header->size + sizeof(struct MHeader));
    }
}

char verif_enought_space(struct MHeader *header, size_t target)
{
    if (target < header->size + sizeof(struct MHeader))
    {
        reorga_page(header, target);
        return 1;
    }

    if (header->size == target || target < header->size)
    {
        return 1;
    }

    return 0;
}

__attribute__((visibility("default"))) void *realloc(void *ptr, size_t size)
{
    if (size == 0)
    {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL)
    {
        return real_malloc(size);
    }

    size_t real_size = (size & ~(0xf)) + (0x10 * !!(size & 0xf));
    struct MHeader *header = ptr;
    header--;

    if (verif_enought_space(header, real_size))
    {
        return ptr;
    }

    if (header->next && header->next->is_free)
    {
        header->size += header->next->size + sizeof(struct MHeader);
        header->next = header->next->next;

        if (verif_enought_space(header, real_size))
        {
            return ptr;
        }
    }
    if (header->prev && header->prev->is_free)
    {
        header->prev->size += header->size + sizeof(struct MHeader);
        header->prev->next = header->next;

        if (verif_enought_space(header, real_size))
        {
            struct MHeader *prev = header->prev;

            void *data = prev + 1;

            memmove(ptr, data, header->size);

            return data;
        }
    }

    size_t old_size = header->size;

    void *tmp = real_malloc(old_size);

    memcpy(tmp, ptr, old_size);
    free(ptr);

    void *res = real_malloc(real_size);

    memcpy(res, tmp, old_size);
    free(tmp);

    return res;
}

__attribute__((visibility("default"))) void *calloc(size_t nmemb, size_t size)
{
    char *res;
    size_t s = nmemb * size;
    if (s < (nmemb < size ? nmemb : size))
    {
        return NULL;
    }
    if (!(res = real_malloc(nmemb * size)))
    {
        return NULL;
    }

    for (size_t i = 0; i < nmemb * size; i++)
    {
        res[i] = 0;
    }

    return res;
}
