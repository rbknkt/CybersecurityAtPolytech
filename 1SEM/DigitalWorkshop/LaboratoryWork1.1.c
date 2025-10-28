#include <stdio.h>

unsigned main()
{
	unsigned a, b;
	a = 4294967295;
	while (a % 71585 != 0) {
		a = a - 1;
	}
	while (a != 71585) {
		printf("%u ", a);
		a = a - 71585;
	}
	printf("%u", a);
}