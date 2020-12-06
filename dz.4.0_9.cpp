#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100000


int main() {
    char mas[N];

    FILE* file = fopen("Name1.txt", "rt");
    char c;
    int n = 10;
    int k = 0;
    while (1) {
        if (feof(file)) break;
        c = getc(file);
        mas[k++] = (char)c;
    }
    fclose(file);

    FILE* file1 = fopen("Name2.txt", "wt");
    int m = 0;
    for (int i = 0; i < k; ++i) {
        if ((mas[i - 1] == ' ') && (mas[i] == ' ')) {
            continue;
        }
        m++;
        if (m % n == 0) {
            fputc('\n', file1);
        }
        if (mas[i] == '\n') {
            continue;
        }
        fputc((mas[i]), file1);

    }
}
