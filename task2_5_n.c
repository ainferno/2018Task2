#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int a)
{
    int b = 1;
    for(;a > 0;a--)
        b*=a;
    return b;
}

int min(int a)
{
    int i = 1;
    for(;fact(i)%a!=0;i++);
    return i;
}

unsigned long long int sum(int m,int n)
{
    int i = 0;
    char c;
    unsigned long long int res = 0;
    for(i = m;i <= n;i++)
    {
        res+=min(i);
        printf("%Lu\n",res);
        //scanf("%c",&c);
    }

    return res;
}

int main()
{
    //int a = 0,b = 0;
    //for(;a % 25 != 0)
    printf("%Lu\n",sum(1500000,1600000));
    return 0;
}
