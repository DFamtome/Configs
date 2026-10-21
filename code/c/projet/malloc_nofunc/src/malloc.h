#ifndef MALLOC_H
#define MALLOC_H

#include <pthread.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096
#define NB_PAGES 512

struct MHeader
{
    char is_free;
    size_t size;
    struct MHeader *next;
    struct MHeader *prev;
};

typedef struct APages
{
    size_t nb_alloc;
    void *pages[NB_PAGES];
} APages;

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t number, size_t size);
void *realloc(void *ptr, size_t size);

#endif /* ! MALLOC_H */
