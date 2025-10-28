#include <stdio.h>
#include <ctype.h>

int main() {
    char str[101];
    fgets(str, 101, stdin);

    int max_len = 0;
    int max_start = 0;
    int len = 0;
    int start = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            if (len > max_len) {
                max_len = len;
                max_start = start;
            }
            len = 0;
            start = i + 1;
        }
        else {
            len++;
        }
    }

    if (len > max_len) {
        max_len = len;
        max_start = start;
    }

    for (int i = max_start; i < max_start + max_len; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }

    printf("%s", str);

    return 0;
}