#include<stdio.h>
#include<setjmp.h>

jmp_buf begin;

char curlex, lastlex;
double prev;
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
    lastlex='\0';
    printf("==>");
    getlex();
    result=expr();
    if (curlex != '\n') error();
    printf("\n%.10g\n",result);
    return 0;
}
void getlex()
{
//    prev_lex = curlex;
    while ((curlex=getchar()) == ' ');
}
void error(void)
{
//    printf("\nERROR! c = %c\n", curlex);
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
    while (curlex == '+' || curlex == '-' || curlex == '^')
    {
        if(curlex == '+')
        {
            lastlex='+';
            getlex();
            e+=add();
        }
        else
        {
            if(curlex == '-')
            {
                lastlex='-';
                getlex();
                e-=add();
            }
        }
        if(curlex == '^')
        {
            int helper = prev;
            getlex();
//            printf("Point1: E = %lf, Prev = %lf, Cur = %c\n",e,helper, curlex);
            switch(lastlex)// NOT OPTIMAL BUT NO TIME TO EDIT
            {
                case '+':
                    e-=helper;
                    e+=degree(helper,mult());
                    break;
                case '-':
                    e+=helper;
                    e-=degree(helper,mult());
                    break;
                case '*':
                    e/=helper;
                    e*=degree(helper,mult());
                    break;
                case '/':
                    e*=helper;
                    e/=degree(helper,mult());
                    break;
            }
//            printf("Point2: E = %lf, Prev = %lf, Cur = %c\n",e,helper, curlex);
        }
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
            lastlex='*';
            getlex();
            a*=mult();
        }
        if(curlex == '/')
        {
            lastlex='/';
            getlex();
            a/=mult();
        }
    }
    return a;
}
int mult()
{
    int m;
//    printf("CURLEX = %c ", curlex);
    switch(curlex)
    {
        case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7':case '8': case '9':
            m=curlex-'0';
            prev=m;
            break;
        case '(':
               getlex();
               m=expr();
               prev=m;
        if (curlex == ')')
            break;
        default :
            error();
    }
//    printf("FIN\n");
    getlex();
    return m;
}
