#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    int id = fork();
    int n;
    if (id == 0)
        n = 6;
    if (id != 0)
        n = 1;
    if (id != 0)
        wait(&id);
    int i;
    for (i = n; i < n + 5; i++)
    {
        printf("%d\n", i);
        fflush(stdout);
    }
    return (0);
}