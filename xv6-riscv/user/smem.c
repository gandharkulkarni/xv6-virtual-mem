#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char **argv)
{
    int r;
    int id;
    char *p;

    p = (char *)0x40000000;

    r = smem(p, 4 * 4096);
    printf("smem: %d\n", r);

    p[0] = 'a';

    id = fork();
    if (id == 0)
    {
        p[0] = 'b';
        exit(0);
    }

    wait(0);
    if (p[0] == 'b')
    {
        printf("success\n");
    }
    return 0;
}
