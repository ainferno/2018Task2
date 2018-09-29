#include<stdio.h>
#include<setjmp.h>
jmp_buf begin;
char curlex;
void getlex(void);
double degr(double, int);//degr(a,n) = a^n
double expr(void);
double add(void);
double mult(void);
double mult2(void);//second step to check for degree, (+,-) <- (*,/) <- (^)
void error();
int main()
{
    double result;
    setjmp(begin);
    printf("==>");
    getlex();
    result=expr();
    if(curlex != '\n')
        error();
    printf("\n%lf\n",result);
    return 0;
}
void getlex()
{
    while((curlex=getchar()) == ' ');
}
void error(void)
{
    printf("\nERROR! CURLEX = %c\n", curlex);
    while(getchar() != '\n');
    longjmp(begin,1);
}
double degr(double a, int b)
{
    double c = 1;
    for(;b > 0;b--)
        c*=a;
    return c;
}
double expr()
{
    double e=add();
    while(curlex == '+' || curlex == '-')
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
    return e;
}
double add()
{
    double a=mult2();
    while(curlex == '*' || curlex == '/')
    {
        if(curlex == '*')
        {
            getlex();
            a*=mult2();
        }
        else
        {
            if(curlex == '/')
            {
                getlex();
                a/=mult2();
            }
        }
    }
    return a;
}

double mult2()//Alternate function that checks for ^
{
//    printf("POINT0 cur = %c\n", curlex);
    double a = mult();
//    int trigger = 0;//Spec trigger that is set 1 if the degree is  <0
    while(curlex == '^')
    {
        getlex();
//        if(curlex == '-')//Here we check if degree is <0
//        {
//            trigger = 1;
//            getlex();
//        }
//        if(trigger)
//            a = 1/degr(a,mult());//If degree <0 => a = 1/a^x
//        else
        a = degr(a,mult2());//If degree >=0 => a = a^x
//        trigger = 0;
    }
//    printf("POINT3 cur = %c\n", curlex);
    return a;
}

double mult()
{
    double m;
    switch(curlex)
    {
        case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9':
            m = curlex-'0';
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
