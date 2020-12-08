#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char* newS = (char*)malloc(256);
    char* newStr = fgets(newS, 256, stdin);
    char* before = (char*)malloc(1);
    char* after = (char*)malloc(1);
    char* between = (char*)malloc(1);
    int previous = 0;
    int doubledotCount = 0;
    for (int i = 0; i < strlen(newStr); ++i) {
        if (newStr[i] == ':' || i == strlen(newStr) - 1) {
            if (doubledotCount == 1) {
                between = (char*)malloc(i - previous);
                for (int j = previous; j < i; ++j) {
                    between[j - previous] = newStr[j];
                }
                previous = i + 1;
                doubledotCount += 1;
            }
            else if (doubledotCount == 0) {
                before = (char*)malloc(i - previous + 1);
                for (int j = previous; j <= i; ++j) {
                    before[j] = newStr[j];
                }
                previous = i + 1;
                doubledotCount += 1;
            }
            else if (i == strlen(newStr) - 1) {
                after = (char*)malloc(i - previous + 1);
                for (int j = previous; j <= i; ++j) {
                    after[j - previous] = newStr[j];
                }
                previous = i + 1;
                doubledotCount += 1;
            }
        }
    }
    printf("Before: %s\n", before);
    printf("after 1: %s\n", between);
    if (strlen(after)) {
        printf("after 2: %s\n", after);
    }
    return 0;
}