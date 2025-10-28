#include "stdio.h"
#include "string.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    else if (a <= b) {
        return a;
    }
}
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else if (a <= b) {
        return b;
    }
}
int strl(const char* str) {
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }

    return count;
}
const char* nulls(char* s, char* g) {
    static char k[10000];
    int l = 0;
    for (int i = 0; i <= max(strl(s), strl(g)) - min(strl(s), strl(g)); i++) {
        k[i] = 48;
        l = i;
    }
    if (strl(s) > strl(g)) {
        char* p = g;
        while (*p) {
            k[l++] = *p;
            p++;
        }
    }
    else {
        char* p = s;
        while (*p) {
            k[l++] = *p;
            p++;
        }
    }
    return k;
}
int strcomp(const char* s1, const char* s2) {
    if (strl(s1) == strl(s2)) {
        const unsigned char* p1 = (const unsigned char*)s1;
        const unsigned char* p2 = (const unsigned char*)s2;

        while (*p1 && *p1 == *p2) ++p1, ++p2;

        return (*p1 > *p2) - (*p2 > *p1);
    }
    if (strl(s1) > strl(s2)) {
        return 1;
    }
    if (strl(s1) < strl(s2)) {
        return -1;
    }

}
const char* sub(char* q, char* w) {
    static char res[10000];
    int cmp_res = strcomp(q, w);
    if (cmp_res == 0) {
        return "0";
    }
    if (cmp_res == 1) {
        int i = strl(w) - 1;
        while (i >= 0) {
            if (q[i] < w[i]) {
                q[i - 1] -= 1;
                res[i] = 58 + q[i] - w[i];
                i--;
            }
            else {
                res[i] = q[i] - w[i] + 48;
                i--;
            }
        }
        int was = 0, count = 0;
        static char total[10000];
        for (int i = 0; i < strlen(res); i++) {
            if (res[i] == 48 && was == 0) {
                continue;
            }
            if (res[i] != 48) {
                was = 1;
            }
            if (was == 1) {
                total[count] = res[i];
                count++;
            }
        }
        return total;
    }
    else if (cmp_res == -1) {
        int i = strl(q) - 1;
        while (i >= 0) {
            if (w[i] < q[i]) {
                w[i - 1] -= 1;
                res[i] = 58 + w[i] - q[i];
                i--;
            }
            else {
                res[i] = w[i] - q[i] + 48;
                i--;
            }
        }
    }
    int was = 0, count = 0;
    static char total[10000] = { "\0" };
    for (int i = 0; i < strlen(res); i++) {
        if (res[i] == 48 && was == 0) {
            continue;
        }
        if (res[i] != 48) {
            was = 1;
        }
        if (was == 1) {
            total[count] = res[i];
            count++;
        }
    }
    return total;
}
const char* add(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = max(len1, len2);
    int holder = 0;
    static char result[10000] = { "\0" };
    int i, j, k;
    for (i = len1 - 1, j = len2 - 1, k = 0; i >= 0 || j >= 0 || holder > 0; i--, j--, k++) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + holder;
        result[k] = '0' + (sum % 10);
        holder = sum / 10;
    }
    if (holder > 0) {
        result[k] = '0' + holder;
        k++;
        result[k] = '\0';
    }
    result[k] = '\0';
    for (i = 0, j = k - 1; i < j; i++, j--) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }

    return result;
}
const char* mult(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1 + len2;
    char result[10000] = { "\0" };
    memset(result, '0', len);
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = len2 - 1; j >= 0; j--) {
            int prod = (num1[i] - 48) * (num2[j] - 48) + carry;
            carry = prod / 10;
            int pos = i + j + 1;
            int sum = (result[pos] - 48) + prod % 10;
            result[pos] = (sum % 10) + 48;
            carry += sum / 10;
        }
        if (carry > 0) {
            int pos = i;
            int sum = (result[pos] - 48) + carry;
            result[pos] = (sum % 10) + 48;
        }
    }
    int start = 0;
    while (result[start] == '0' && start < len - 1) {
        start++;
    }
    static char final[10000] = { "\0" };
    strcpy(final, result + start);
    return final;
}
int multiply(int x, int res[], int res_size) {
    int carry = 0;
    for (int i = 0; i < res_size; i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry) {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}
void factorial(int n) {
    int res[100000];
    res[0] = 1;
    int res_size = 1;
    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);
    for (int i = res_size - 1; i >= 0; i--)
        printf("%d", res[i]);
}
void power(char* num, int pow) {
    char result[10000] = { "\0" };
    strcpy(result, "1");
    for (int i = 0; i < pow; i++) {
        char* temp = mult(result, num);
        strcpy(result, temp);
    }
    printf("%s\n", result);
}
const char* range_sum(char* start, char* end) {
    static char sum[1000] = { "\0" };
    int flag = 0;
    if (start[0] == '-' && end[0] == '-') {
        printf("-");
        start++;
        end++;
        flag = 1;
    }
    if (flag == 1) {
        while (strcomp(end, start) <= 0) {
            char* f = add(sum, end);
            strcpy(sum, f);
            char* temp = add(end, "1");
            strcpy(end, temp);
        }
        printf("%s\n", sum);
    }
    else {
        if (start[0] != '-') {
            while (strcomp(start, end) <= 0) {
                char* f = add(sum, start);
                strcpy(sum, f);
                char* temp = add(start, "1");
                strcpy(start, temp);
            }
            printf("%s\n", sum);
        }
        if (start[0] == '-' && end[0] != '-') {
            start++;
            static char sum1[1000] = "0";
            static char sum2[1000] = "0";
            char beg1[1000] = "0", beg2[1000] = "0";
            while (strcomp(beg1, start) <= 0) {
                char* f = add(sum1, beg1);
                strcpy(sum1, f);
                char* temp = add(beg1, "1");
                strcpy(beg1, temp);
            }
            while (strcomp(beg2, end) <= 0) {
                char* t = add(sum2, beg2);
                strcpy(sum2, t);
                char* r = add(beg2, "1");
                strcpy(beg2, r);
            }
            if (strcomp(sum1, sum2) == 1) {
                printf("-");
                printf("%s\n", sub(sum1, nulls(sum2, sum1)));
            }
            if (strcomp(sum1, sum2) == -1) {
                printf("%s\n", sub(sum2, nulls(sum1, sum2)));
            }
            if (strcomp(sum1, sum2) == 0) {
                printf("0");
            }
        }
    }
}
int main() {
    printf("----------СПРАВКА----------\n1. '-' вычитание\n2. '+' сложение\n3. '*' умножение\n4. '^' возведение в степень\n5. '!' факториал\n6. 's' сумма чисел от и до\n---------------------------\n");
    char action;
    printf("Выберете действие:");
    scanf("%c", &action);
    if (action == '-' || action == '1') {
        char st[1000] = { "\0" }, st0[1000] = { "\0" };
        printf("Введите число 1:");
        scanf("%s", &st);
        printf("Введите число 2:");
        scanf("%s", &st0);
        char* a = st;
        char* b = st0;
        if (a[0] == '-' && b[0] == '-') {
            a++;
            b++;
            if (strcomp(a, b) == 1) {
                printf("-");
                printf("%s\n", sub(a, nulls(a, b)));
            }
            else {
                printf("%s\n", sub(b, nulls(b, a)));
            }
        }
        else if (a[0] == '-' && b[0] != '-') {
            a++;
            printf("-");
            printf("%s\n", add(a, b));
        }
        else if (a[0] != '-' && b[0] == '-') {
            b++;
            printf("%s\n", add(a, b));
        }
        else if (a[0] != '-' && b[0] != '-') {
            if (strcomp(a, b) != -1) {
                printf("%s\n", sub(a, nulls(a, b)));
            }
            else {
                printf("-");
                printf("%s\n", sub(b, nulls(b, a)));
            }
        }
    }
    else if (action == '+' || action == '2') {
        char st1[1000] = { "\0" }, st2[1000] = { "\0" };
        printf("Введите число 1:");
        scanf("%s", &st1);
        printf("Введите число 2:");
        scanf("%s", &st2);
        char* c = st1;
        char* d = st2;
        if (c[0] == '-' && d[0] == '-') {
            c++;
            d++;
            printf("-");
            printf("%s\n", add(c, d));
        }
        else if (c[0] == '-' && d[0] != '-') {
            c++;
            if (strcomp(c, d) == 1) {
                printf("-");
                printf("%s\n", sub(c, nulls(c, d)));
            }
            else if (strcomp(c, d) == -1) {
                printf("%s\n", sub(d, nulls(d, c)));
            }
            else if (strcomp(c, d) == 0) {
                printf("0");
            }
        }
        else if (c[0] != '-' && d[0] == '-') {
            d++;
            if (strcomp(c, d) == 1) {
                printf("%s\n", sub(c, nulls(c, d)));
            }
            else if (strcomp(c, d) == -1) {
                printf("-");
                printf("%s\n", sub(d, nulls(d, c)));
            }
            else if (strcomp(c, d) == 0) {
                printf("0");
            }
        }
        else if (c[0] != '-' && d[0] != '-') {
            printf("%s\n", add(c, d));
        }
    }
    else if (action == '*' || action == '3') {
        char st3[1000] = { "\0" }, st4[1000] = { "\0" };
        printf("Введите число 1:");
        scanf("%s", &st3);
        printf("Введите число 2:");
        scanf("%s", &st4);
        char* e = st3;
        char* f = st4;
        if (strcomp(e, "0") == 0 || strcomp(f, "0") == 0) {
            printf("0");
        }
        else if (e[0] == '-' && f[0] == '-') {
            e++;
            f++;
            printf("%s\n", mult(e, f));
        }
        else if (e[0] == '-' && f[0] != '-') {
            e++;
            printf("-");
            printf("%s\n", mult(e, f));

        }
        else if (e[0] != '-' && f[0] == '-') {
            f++;
            printf("-");
            printf("%s\n", mult(e, f));
        }
        else if (e[0] != '-' && f[0] != '-') {
            printf("%s\n", mult(e, f));
        }
    }
    else if (action == '^' || action == '4') {
        char num[1000] = { "\0" };
        printf("Введите основание:");
        scanf("%s", &num);
        char* t = num;
        int p;
        printf("Введите показатель:");
        scanf("%d", &p);
        if (t[0] == '-' && p % 2 == 0) {
            t++;
            power(t, p);
        }
        else if (t[0] == '-' && p % 2 == 1) {
            t++;
            printf("-");
            power(t, p);
        }
        else if (t[0] != '-') {
            power(t, p);
        }
    }
    else if (action == '!' || action == '5') {
        int num;
        printf("Введите число: ");
        scanf("%d", &num);
        factorial(num);
    }
    else if (action == 's' || action == '6') {
        char st5[1000] = { "\0" }, st6[1000] = { "\0" };
        printf("Введите число 1:");
        scanf("%s", &st5);
        printf("Введите число 1:");
        scanf("%s", &st6);
        range_sum(st5, st6);
    }
}