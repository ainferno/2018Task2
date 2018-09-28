#include<stdio.h>
#include<setjmp.h>

jmp_buf begin;

char curlex;
void getlex(void);
double expr(void);
double add(void);
double degree(double, unsigned int);
int mult(void);
void error();
main()
{
    double result;
    setjmp(begin);
    printf("==>");
    getlex();
    result=expr();
    if (curlex != '\n') error();
    printf("\n%.10g\n",result);
    return 0;
}
void getlex()
{
    while ((curlex=getchar()) == ' ');
}
void error(void)
{
    printf("\nERROR!\n");
    while(getchar()!='\n');
    longjmp(begin,1);
}

double degree(double a, unsigned int b)
{
    int i = 0;
    double c = 1;
    for(;i < b;i++)
        c*=a;
    return c;
}

double expr()
{
    double e=add();
    while (curlex == '+' || curlex == '-')
    {
        if(curlex == '+')
        {
            getlex();
            e+=add();
        }
        else
        {
            if(curlex == '-')
            {
                getlex();
                e-=add();
            }
        }
    }
    if(curlex == '^')
    {
        getlex();
        e = degree(e,expr());
    }
    return e;
}
double add()
{
    double a=mult();
    while (curlex == '*' || curlex == '/')
    {
        if(curlex == '*')
        {
            getlex();
            a*=mult();
        }
        if(curlex == '/')
        {
            getlex();
            a/=mult();
        }
    }
    return a;
}
int mult()
{
    int m;
    switch(curlex)
    {
        case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7':case '8': case '9':
            m=curlex-'0';
            break;
        case '(':
               getlex();
               m=expr();
        if (curlex == ')')
            break;
        default :
            error();
    }
    getlex();
    return m;
}
