#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<fstream>
#include<string.h>

typedef
struct Bagage
{
	int kilkist;
	int masa;
}Bagage;

Bagage vvod_Bagage()
{
	Bagage res;
	printf("kilkist = ");
	scanf("%d", &res.kilkist);
	printf("masa = ");
	scanf("%d", &res.masa);
	return res;
}

int main() {
	int n;
	printf("%s", "kilkist passangers: ");
	scanf("%d", &n);
	FILE* f1 = fopen("passengers.bin", "wb");
	char pass[50];
	for (int i = 0; i < n; i++) {
		printf("\n%s", "passanger: ");
		scanf("%s", pass);
		fwrite(&pass, 1, sizeof(char), f1);
	}
	fclose(f1);
	FILE* f2 = fopen("bagage.bin", "wb");
	Bagage b;
	for (int i = 0; i < n; i++) {
		printf("\n%s", "bagage passanger # ");
		printf("%d", i + 1);
		printf("\n");
		b = vvod_Bagage();
		fwrite(&b, 1, sizeof(Bagage), f2);
	}
	fclose(f2);
	float average_vaga = 0.0;
	int kilkist = 0;
	FILE* f3 = fopen("passengers.bin", "rb");
	FILE* f4 = fopen("bagage.bin", "rb");
	while (!feof(f4)) {
		int r = fread(&b, 1, sizeof(Bagage), f4);
		average_vaga += b.masa / b.kilkist;
		kilkist += b.kilkist;
	}
	fclose(f4);
	FILE* f5 = fopen("bagage.bin", "rb");
	for (int i = 0; i < n; i++) {
		int r = fread(&b, 1, sizeof(Bagage), f5);
		int k = fread(&pass, 1, sizeof(char), f3);
		if (abs(b.masa / b.kilkist - (average_vaga / n)) <= 1) {
			printf("\n%s", "average masa rechey passangera <= 1: ");
			printf("%s", pass, "%\n");
		}
		if (b.kilkist > 2) {
			printf("\n%s", "bilshe dvoch rechey maje: ");
			printf("%s", pass, "%\n");
		}
		if (b.kilkist > kilkist / n) {
			printf("\n%s", "bilshe average kilkosti rechey maje: ");
			printf("%s", pass, "%\n");
		}
	}
	fclose(f3);
	fclose(f5);

}
