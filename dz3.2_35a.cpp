#include <stdio.h>
#include <string.h>


int main() {
    char newstr[256];
    char* c = fgets(newstr, 256, stdin);
    int hash = 0;
    for (int i = 0; i < strlen(c) - 1; i += 4) {
        int counter = 0;
        for (int j = i; j < i + 4; j++) {
            counter <<= 8;
            if (j < strlen(c) - 1) {
                counter += c[j];
            }
            else {
                counter += c[strlen(c) - 1 - ((j - strlen(c) + 2))];
            }
        }
        hash ^= counter;
    }
    printf("Hash is: %d\n", hash);
}