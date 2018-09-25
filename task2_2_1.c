#include <stdio.h>


double polynomial(double a,double b, double x)
{
    return a + b * x;
}

int main()
{
    double x = 0, a = 0,b = 0;
    printf("Enter x:");
    scanf("%lf",&x);
    while(scanf("%lf",&a) == 1)
        b = polynomial(a,b,x);
    printf("Result is: %.10g\n", b);
    return 0;
}
