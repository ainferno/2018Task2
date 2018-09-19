#include <stdio.h>


int fib(int a)
{
    if(a == 0)
        return 0;
    if(a == 1)
        return 1;
    return fib(a-1)+fib(a-2);
}

int main()
{
    int a = 0;

    do
    {
        scanf("%d",&a);
        if(a!=322)
            printf("%d\n",fib(a));
    }
    while(a != 322);
    return 0;
}
