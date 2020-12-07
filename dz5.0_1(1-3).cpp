#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cmath>
#include<time.h>

typedef
struct Price
{
	int hrivna;
	int cop;
}Price;

Price vvod_Price()
{
	Price res;
	printf("hrivna = ");
	scanf("%d", &res.hrivna);
	printf("cop = ");
	scanf("%d", &res.cop);
	return res;
}

void vyvod_Price(const Price x)
{
	printf("hrivna = %d\n", x.hrivna);
	printf("cop = %d\n", x.cop);
}

typedef
struct Time
{
	int hour;
	int min;
	int sec;
}Time;

Time vvod_Time()
{
	Time res;
	printf("hour = ");
	scanf("%d", &res.hour);
	printf("min = ");
	scanf("%d", &res.min);
	printf("sec = ");
	scanf("%d", &res.sec);
	return res;
}

void vyvod_Time(const Time x)
{
	Time res;
	printf("hour = %d\n", x.hour);
	printf("min = %d\n", x.min);
	printf("sec = %d\n", x.sec);
}

typedef
struct Date
{
	int day;
	int month;
	int year;
}Date;

Date vvod_Date()
{
	Date res;
	printf("day = ");
	scanf("%d", &res.day);
	printf("month = ");
	scanf("%d", &res.month);
	printf("year = ");
	scanf("%d", &res.year);
	return res;
}

void vyvod_Date(const Date x)
{
	Date res;
	printf("day = %d\n", x.day);
	printf("month = %d\n", x.month);
	printf("year = %d\n", x.year);
}

int main()
{
	Price x;
	x = vvod_Price();
	vyvod_Price(x);
	Time y;
	y = vvod_Time();
	vyvod_Time(y);
	Date z;
	z = vvod_Date();
	vyvod_Date(z);
	getchar();
	getchar();
}

