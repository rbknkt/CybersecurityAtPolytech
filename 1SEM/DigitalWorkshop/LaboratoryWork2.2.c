#include <stdio.h>

#define MAX_SIZE 10000

int main() {
    int n, i, j, count, unique_count = 0;
    int arr[MAX_SIZE];
    int freq[MAX_SIZE] = { 0 };

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        count = 1;
        if (freq[i] == 0) {
            for (j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = -1;
                }
            }
            if (count <= 3) {
                unique_count++;
            }
        }
    }

    printf("%d\n", unique_count);

    return 0;
}