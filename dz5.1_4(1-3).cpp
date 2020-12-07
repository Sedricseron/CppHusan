#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cout << "vvedit kilkist komponent" << endl;
	cin >> n;
	FILE* f1 = fopen("qwer.bin", "wb");
	for (int i = 0; i < n; i++) {
		int p;
		cout << "vvedit komponentu no." << i << ": ";
		cin >> p;
		fwrite(&p, 1, sizeof(int), f1);
	}
	fclose(f1);
	FILE* f2 = fopen("qwer.bin", "rb");
	int i = 0;
	int j = 0;
	int k = 0;
	int maximal, minimal, p;
	while (!feof(f2)) {
		int r = fread(&p, 1, sizeof(int), f2);
		if (r < sizeof(int)) break;
		if (p % 2 == 0) {
			if (i == 0) maximal = p;
			i++;
			if (p > maximal) maximal = p;
		}
		else {
			if (k == 0) minimal = p;
			if (p < minimal) minimal = p;
			if ((sqrt(p) - (int)sqrt(p))==0) j++;
			k++;
		}
	}
	fclose(f2);
	cout << "kilkist parnych chysel:" << i << endl << "kilkist kvadrativ neparnych chysel:" << j << endl << "riznytsa miz max parnym chyslom i min neparnym:" << maximal - minimal;

}