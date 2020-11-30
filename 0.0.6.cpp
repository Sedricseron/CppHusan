#include <stdio.h>
#include <math.h>
//#include<iostream>

int main()
{
	double m1 = 1000;
	double m2 = 2000;
	double r = 300;
	long double y = 6.673 * (pow(10,-11));
	printf("%le\n", y);
	printf("F1= %Lf\n", (m1 * m2) / pow(r,2));
	printf("F1= %le\n", (m1 * m2) / pow(r, 2));
	getchar();
}