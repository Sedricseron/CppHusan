#include <stdio.h>
//#include<iostream>

int main()
{
	int a, b, c, d;
	a = 2;
	b = 31;
	printf("%d\n", a + b);
	printf("%d\n", 45 * 54 - 11);
	c = 15 / 4;
	printf("%d\n", c);
	//printf("%lf\n", c); - Хочемо вивести double, а у нас int
	double cl = 15.0 / 4;
	printf("%lf\n", cl);
	d = 67 % 5;
	printf("%d\n", d);
	double e = (2 * 45.1 + 3.2) / 2;
	printf("%lf\n", e);
	getchar();
}