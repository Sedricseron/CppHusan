#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100000


int main() {
    char mas[N];
    char mas2[N];

    FILE* file = fopen("txtF.txt", "rt");
    char c;
    int k = 0;
    while (1) {
        if (feof(file)) break;
        c = getc(file);
        mas[k++] = (char)c;
    }
    fclose(file);

    FILE* file1 = fopen("txtH.txt", "wt");

    for (int i = 0; i < k; ++i) {
        fputc((mas[i]), file1);
    }

    FILE* file2 = fopen("txtG.txt", "rt");
    k = 0;
    while (1) {
        if (feof(file2)) break;
        c = getc(file2);
        mas2[k++] = (char)c;
    }
    fclose(file2);

    FILE* file3 = fopen("txtH.txt", "a");

    for (int i = 0; i < k; ++i) {
        fputc((mas2[i]), file3);
    }
}
