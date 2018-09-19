#include <stdio.h>


double polynomial(double a,double b, double x)
{
    return a + b * x;
}

int main()
{
    double x = 0, eps = 0.0001,a = 0,b = 0;

    scanf("%lf",&x);
    do
    {
        scanf("%lf",&a);
        if(a!=322)
            b = polynomial(a,b,x);
    }
    while(a != 322);
    printf("Result is: %.10g\n", b);
    return 0;
}
