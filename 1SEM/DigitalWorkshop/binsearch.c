#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int main()
{
    int* mass;
    int i, n, left = 0, a, low = 0, high, middle, k;
    scanf("%d", &n);
    mass = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &mass[i]);
    }
    scanf("%d", &a);
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (a < mass[middle])
        {
            high = middle - 1;
        }
        else if (a > mass[middle])
        {
            low = middle + 1;
        }
        else
        {
            k = middle;
            break;
        }
        k = -1;
    }
    if (k != -1)
    {
        printf("%d", k);
        return 0;
    }
    else
    {
        printf("notfound");
        return 0;
    }
}