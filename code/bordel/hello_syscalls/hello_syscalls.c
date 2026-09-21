#include <unistd.h>

int main(void)
{
    return write(STDOUT_FILENO, "Hello World!\n", 13) == -1 ? 1 : 0;
}
