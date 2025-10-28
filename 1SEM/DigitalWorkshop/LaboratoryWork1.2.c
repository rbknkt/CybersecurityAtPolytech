#include <stdio.h>

void convert_and_print(unsigned long long num, int base, int is_negative) {
    char res[65];
    int index = 0;

    do {
        int digit = num % base;
        res[index++] = (digit > 9) ? (digit - 10) + 'a' : digit + '0';
        num /= base;
    } while (num != 0);
    if (is_negative) printf("-");
    for (int i = index - 1; i >= 0; i--) printf("%c", res[i]);
}

int main() 
{
    short a = 0x7FFF;
    int b = 0x66BACAD4;
    unsigned int c = 0xEF04F460;
    long d = 0x2F453BE0;
    unsigned long e = 0x1E5CFCBA;

    printf("short;");
    convert_and_print(a, 16, 0);
    printf("=");
    convert_and_print(a, 13, 0);
    printf(";13\n");
    printf("int;", b);
    convert_and_print(b, 16, 0);
    printf("=");
    convert_and_print(b, 18, 0);
    printf(";18\n");
    printf("unsigned int;");
    convert_and_print(c, 16, 0);
    printf("=");
    convert_and_print(c, 14, 0);
    printf(";14\n");
    printf("long;");
    convert_and_print(d, 16, 1);
    printf("=");
    convert_and_print(d, 31, 1);
    printf(";31\n");
    printf("unsigned long;");
    convert_and_print(e, 16, 0);
    printf("=");
    convert_and_print(e, 24, 0);
    printf(";24\n");
    return 0;
}
