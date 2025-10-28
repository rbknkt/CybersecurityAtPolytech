#include <stdio.h>
#include <limits.h>

int main() {
    int exp = 5;
    long base = 0;
    long prev_result = 0;
    long result = 1;

    while (1) {
        for (int i = 0; i < exp; ++i) {
            if (base > 0 && LONG_MAX / base < result) {
                return 0;
            }
            result *= base;
        }
        if (result == 0) {
            printf("%ld\n", result);
        }
        if (result < prev_result) {
            return 0;
        }
        if (result != 0) {
            printf("%ld\n", result);
            printf("-%ld\n", result);
        }
        prev_result = result;
        result = 1;
        ++base;
    }
    return 0;
}
