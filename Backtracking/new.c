#include <stdio.h>
#include <stdlib.h>

struct School
{
    int age;
    int rollno;
};

void solve()
{
    struct School sc;
    sc.age = 19;
    sc.rollno = 82;
    printf("%d %d", sc.age, sc.rollno);
}

int main()
{
    solve();
    return 0;
}
