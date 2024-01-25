#include <stdio.h>
#include <string.h>
#include <internal/io.h>
int puts(const char *str)
{
    int w1 = write(1, str, strlen(str));
    int w2 = write(1, "\n", 1);
    if (w1 < 0 || w2 < 0)
        return -1;
    return 0;
}
