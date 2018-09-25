#include <stdio.h>
#include <stdlib.h>

double polinomial(double x,double a,double b)
{
    return a + b*x;
}

int main()
{
    double x,a,b = 0,pr = 0;
    printf("Enter x:");
    scanf("%lf",&x);
    while(scanf("%lf",&a)==1)
    {
        pr = pr * x + b;
        b = polinomial(x,a,b);
    }
    printf("Pol = %.10g, Der = %.10g\n",b,pr);
    return 0;
}
