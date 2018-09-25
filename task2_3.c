#include <stdio.h>
#include <time.h>

int fib_r(int a)
{
    if(a < 0)
    {
        printf("Error(number too big\n");
        return 0;
    }
    if(a <= 1)
        return a;
    return fib_r(a-1)+fib_r(a-2);
}
int fib_i(int a)
{
    int x = 0, y = 1, z = 0;
    if(a <= 1)
        return a;
    for(;a > 1;a--)
    {
        z = y;
        y = x+y;
        x = z;
    }
    return y;
}

int main()
{
    int a = 0;
    long unsigned int t1 = 0;
    printf("Please, do not enter numbers bigger than 45 it can take too much time\nEnter N:");
    while(scanf("%d",&a)==1)
    {
        t1 = clock();
        printf("Result with iteration is: %d", fib_i(a));
        printf(", It took %d mS\n", clock()-t1);
        t1 = clock();
        printf("Result with recursion is: %d", fib_r(a));
        printf(", It took %d mS\nEnter N:", clock()-t1);
    }

    return 0;
}
