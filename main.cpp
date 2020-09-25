/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

double func1(double x, double y, double z)
{   
    double t = x*y;
    if (t<y*z) {
        t = y*z;
    }
    if (t<x*z) {
        t = y*z;
    }
    return t;
}


int main()
{
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);
    printf("max = %lf", func1(x,y,z));
}
