/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

double func1(double a, double b, double c)
{  
    if (b*b-4*a*c>0) {
        return 2;
    }
     if (a==0 and b==0 and c==0) {
        return -1;
    }
    if (b*b-4*a*c==0 or a==0) {
        return 1;
    }
    if (b*b-4*a*c<0 or (a==0 and b==0)){
        return 0;
    }
}


int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("Text = %lf", func1(a,b,c));
}
