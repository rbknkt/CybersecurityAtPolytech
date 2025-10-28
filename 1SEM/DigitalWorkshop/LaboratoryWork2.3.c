#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n1, n2, n3, n4;
	scanf("%d.%d-%d.%d", &n1, &n2, &n3, &n4);
	int chislo1 = n1 * 10000 + n2;
	int chislo2 = n3 * 10000 + n4;
	int result = chislo1 - chislo2;
	if(result<0)
	{
	printf("-");
	}
	result = abs(chislo1 - chislo2);
    if (result==0)
    {
        printf("%d", result);
        return 0;
    }
    int result1 =result/10000;
    result = result%10000;
    if (result == 0)
    {
        printf("%d", result1);
        return 0;
    }
    if(result<10)
    {
        printf("%d.000%d", result1, result);
        return 0;
    }
    if(result<100)
    {
        if (result%10==0)
        {
            result=result/10;
        }
        printf("%d.00%d", result1, result);
        return 0;
    }
    if(result<1000)
    {
        if (result%10==0)
        {
            result=result/10;
        }
         if (result%10==0)
        {
            result=result/10;
        }
        printf("%d.0%d", result1, result);
        return 0;
    }
    if (result%10==0)
        {
            result=result/10;
        }
         if (result%10==0)
        {
            result=result/10;
        }
        if (result%10==0)
        {
            result=result/10;
        }
    printf("%d.%d", result1, result);
    return 0;
}
