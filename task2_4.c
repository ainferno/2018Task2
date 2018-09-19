#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double step10(double a)
{
    int i;
    double b = 1;
    for(i = 0;i < a;i++,b*=10);
    return b;
}

double str2double(char str[100])
{
    int n = strlen(str), i = 0;
    char c;
    double res = 0,rh = 10;

//    printf("n = %d\n",n);

    for(i = 0;i < n && str[i]!='.' && str[i]!='e' && str[i]!='E';i++)
        res = res * 10 + str[i]-'0';
//    printf("Res = %lf\n",res);
    i++;
    if(str[i-1]=='.')
    {
        for(;i < n && str[i]!='F' && str[i]!='f' && str[i]!='E' && str[i]!='e';i++,rh*=10)
        {   
            res+= ((double)str[i]-'0')/rh;
//        printf("R = %lf, Rh = %lf, R? = %lf, rr = %lf\n",res,rh,(double)str[i]-'0',((double)str[i]-'0')/rh);
        }
        i++;
    }
    if(str[i-1] == 'e' || str[i-1] == 'E')
    {
        c = str[i];
        if(c == '-' || c == '+')
            i++;
        rh = 0;
        for(;i < n && str[i]!='f' && str[i]!='F';i++)
            rh = rh * 10 + (double)str[i]-'0';
        rh = step10(rh);
        (c == '-') ? (res/=rh) : (res*=rh);
    }
    

    return res;
}

int main()
{
    char str[100];
    while(scanf("%s",str)==1)
    {
//        printf("%s\n",str);
        printf("%.10g\n",str2double(str));
    }
	return 0;
}
