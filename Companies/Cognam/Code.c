#include <stdio.h>

void foo(int i)
{
    if (i > 1)
    {
        foo(i / 2);
        foo(i / 2);
    }
    printf("#");
}
int main()
{
    int i = 3, j = 6;
    i = i ^ j;
    j = i ^ j;
    printf("%d %d", i, j);
}