#include <stdio.h>

double mod_lf(double x)
{
    return (x>=0) ? x : -x;
}

double sqrt_lf_2(double x0,double x1,double x2,double eps)
{
//    printf("Point %lf %lf\n",x2,x1);
    if(mod_lf(x2-x1) < eps)
        return x2;
    return sqrt_lf_2(x0,x2,0.5 * (x2 + x0/x2),eps);
}

double sqrt_lf(double x,double eps)
{
    return sqrt_lf_2(x,x,0.5 * (x + x/x),eps);
}

int main()
{
    double x = 0, eps = 0.0001,a = 0,b = 0;
    printf("Enter epsilon: ");
    scanf("%lf", &eps);
    do
    {
        scanf("%lf",&x);
        if(x!=0)printf("sqrt(%.10g) = %.10g\n",x,sqrt_lf(x,eps));
    }
    while(x!=0);
    return 0;
}
