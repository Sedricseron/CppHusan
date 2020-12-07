#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>

typedef
struct Anketa
{
	char name[50];
	char surname[50];
	char sex[1];
	int day;
	int month;
	int year;
}Anketa;

Anketa vvod_Anketa()
{
	Anketa res;
	printf("day = ");
	scanf("%d", &res.day);
	printf("month = ");
	scanf("%d", &res.month);
	printf("year = ");
	scanf("%d", &res.year);
	printf("name = ");
	scanf("%s", res.name);
	printf("surname = ");
	scanf("%s", res.surname);
	printf("sex = ");
	scanf("%s", res.sex);
	return res;
}

void surnames(Anketa* P, char l, int n) {
	for (int i = 0; i < n; i++) {
		if (P[i].surname[0] == l) printf("%s", P[i].surname);
	}
}

void TheOldestMan(Anketa* P, int n) {
	Anketa oldest;
	int minday, minmonth, minyear;
	minday = P[0].day;
	minmonth = P[0].month;
	minyear = P[0].year;
	for (int i = 1; i < n; i++) {
		if (P[i].sex[0] == 'M') {
			if (P[i].year < minyear) {
				if (P[i].month < minmonth) {
					if (P[i].day < minday) oldest = P[i];
				}
			}
		}
	}
	printf("%s", oldest.name);
}


int main()
{
	int i, n;
	scanf("%d", &n);
	Anketa* P = new Anketa[n];
	for (i = 0; i < n; i++)
	{
		P[i] = vvod_Anketa();
	}
	surnames(P, 'H', n);
	TheOldestMan(P, n);

}