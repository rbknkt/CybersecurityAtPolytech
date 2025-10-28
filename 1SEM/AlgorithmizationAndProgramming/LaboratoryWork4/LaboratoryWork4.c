#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell_sort(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;
    clock_t start = clock();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comparisons++;
                arr[j] = arr[j - gap];
                swaps++;
            }
            arr[j] = temp;
        }
    }
    clock_t end = clock();
    printf("Сортировка Шелла:\n");
    printf("Количество сравнений элементов: %d\n", comparisons);
    printf("Количество перемещений элементов: %d\n", swaps);
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время работы сортировки: %f секунд\n", cpu_time_used);
    printf("\n");
}
void comb_sort(int arr2[], int n) {
    int comparisons = 0;
    int swaps = 0;
    int gap = n;
    int swap_made = 1;
    clock_t start = clock();
    while (gap > 1 || swap_made == 1) {
        gap = (gap * 10) / 13;
        if (gap == 9 || gap == 10) gap = 11;
        if (gap < 1) gap = 1;
        swap_made = 0;
        for (int i = 0; i < n - gap; i++) {
            comparisons++;
            if (arr2[i] > arr2[i + gap]) {
                int temp = arr2[i];
                arr2[i] = arr2[i + gap];
                arr2[i + gap] = temp;
                swap_made = 1;
                swaps++;
            }
        }
    }
    clock_t end = clock();
    printf("Сортировка расческой:\n");
    printf("Количество сравнений элементов: %d\n", comparisons);
    printf("Количество перемещений элементов: %d\n", swaps);
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время работы сортировки: %f секунд\n", cpu_time_used);
    printf("\n");
}
void insertion_sort(int arr3[], int n) {
    int i, j, key;
    int comparisons = 0, swaps = 0;
    clock_t start = clock();
    for (i = 1; i < n; i++) {
        key = arr3[i];
        j = i - 1;

        while (j >= 0 && arr3[j] > key) {
            comparisons++;
            swaps++;
            arr3[j + 1] = arr3[j];
            j = j - 1;
        }
        swaps++;
        arr3[j + 1] = key;
    }
    clock_t end = clock();
    printf("Сортировка вставкой:\n");
    printf("Количество сравнений элементов: %d\n", comparisons);
    printf("Количество перемещений элементов: %d\n", swaps);
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Время работы сортировки: %f секунд\n", cpu_time_used);
    printf("\n");
}
int main() {
    int n = 10000;
    int arr[10000], arr2[10000], arr3[10000];
    int i, choice;

    printf("Выберите режим работы программы:\n");
    printf("1. Заполнить массив случайными числами\n");
    printf("2. Загрузить массив из файла\n");
    scanf("%d", &choice);

    if (choice == 1) {
        srand(time(NULL));
        for (i = 0; i < n; i++) {
            arr[i] = rand();
            arr2[i] = rand();
            arr3[i] = rand();
        }
    }
    else if (choice == 2) {
        FILE* fp;
        char filename[100];
        printf("Введите имя файла: ");
        scanf("%s", filename);
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Ошибка при открытии файла\n");
            exit(1);
        }
        for (i = 0; i < n; i++) {
            fscanf(fp, "%d", &arr[i]);
            fscanf(fp, "%d", &arr2[i]);
            fscanf(fp, "%d", &arr3[i]);
        }
        fclose(fp);
    }
    else {
        printf("Неверный выбор\n");
        exit(1);
    }
    shell_sort(arr, n);
    comb_sort(arr2, n);
    insertion_sort(arr3, n);

    return 0;
}
