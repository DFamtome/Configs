#include <err.h>
#include <stdio.h>

FILE *aux_open_file(const char *file_path, const char *mode)
{
    FILE *file = fopen(file_path, mode);
    if (file == NULL)
        err(1, "failed to open %s", file_path);
    return file;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
        errx(1, "Usage: %s TEST_FILE MODE", argv[0]);

    FILE *file = aux_open_file(argv[1], argv[2]);

    printf("initial offset: %ld\n", ftell(file));

    /* write "hello world!\n" */
    if (fputs("hello world!\n", file) == EOF)
        err(1, "fputs() failed");

    printf("after writting hello world: %ld\n", ftell(file));

    /* seek to the w */
    fseek(file, -7, SEEK_CUR);
    printf("after seeking backwards: %ld\n", ftell(file));

    /* write a w over it */
    if (fputc('W', file) == EOF)
        err(1, "fputs() failed");
    printf("after writting a character: %ld\n", ftell(file));

    /* seek to the start */
    fseek(file, 0, SEEK_SET);
    printf("after seeking to 0: %ld\n", ftell(file));

    /* write a H */
    if (fputc('H', file) == EOF)
        err(1, "fputs() failed");
    printf("after printing H: %ld\n", ftell(file));

    /* seek to the start */
    fseek(file, 0, SEEK_SET);
    printf("after seeking to 0: %ld\n", ftell(file));

    /* print the contents of the file */
    puts("file contents:");
    int c;
    while ((c = fgetc(file)) != EOF)
        putchar(c);

    if (ferror(file))
        err(1, "error while reading file");

    printf("after reading the file contents: %ld\n", ftell(file));

    fflush(stdout);

    fclose(file);
    return 0;
}
