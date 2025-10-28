#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func(char* str1, char* str2, char* result) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int q = 0;
    for (int i = 1; i <= len1 && i <= len2; i++) {
        if (strncmp(str1 + len1 - i, str2, i) == 0) {
            q = i;
        }
    }
    strcpy(result, str1);
    strcat(result, str2 + q);
}

int main() {
    int N;
    scanf("%d", &N);
    int size = N * 64;
    char final[100000] = { "\0" };
    for (int i = 0; i < N; i++) {
        char sl1[33], sl2[33], result[65];
        scanf("%s %s", &sl1, &sl2);
        func(sl1, sl2, result);
        strcat(final, result);
        strcat(final, "\n");
    }
    printf("%s", final);
}

