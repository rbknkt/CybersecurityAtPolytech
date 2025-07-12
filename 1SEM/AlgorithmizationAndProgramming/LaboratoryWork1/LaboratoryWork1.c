#include <stdio.h>
#include <conio.h>

int main() {
	// signed char
	signed char sc = 0, sct = 1;
	while (sct > 0) {
		sc = sc + 1;
		sct = sc + 1;
	}
	printf("MAX signed char: %d\n", sc);
	printf("MIN signed char: %d\n\n", sct);

	// unsigned char
	unsigned char uc = 0, uct = 1;
	while (uct > 0) {
		uc = uc + 1;
		uct = uc + 1;
	}
	printf("MAX unsigned char: %d\n", uc);
	printf("MIN unsigned char: %d\n\n", uct);

	// signed int
	signed int si = 0, sit = 1;
	while (sit > 0) {
		si = si + 1;
		sit = si + 1;
	}
	printf("MAX signed int: %d\n", si);
	printf("MIN signed int: %d\n\n", sit);

	// unsigned int
	unsigned int ui = 0, uit = 1;
	while (uit > 0) {
		ui = ui + 1;
		uit = ui + 1;
	}
	printf("MAX unsigned int: %u\n", ui);
	printf("MIN unsigned int: %u\n\n", uit);

	// signed short
	signed short ss = 0, sst = 1;
	while (sst > 0) {
		ss = ss + 1;
		sst = ss + 1;
	}
	printf("MAX signed short: %hd\n", ss);
	printf("MIN signed short: %hd\n\n", sst);

	// unsigned short
	unsigned short us = 0, ust = 1;
	while (ust > 0) {
		us++;
		ust = us + 1;
	}
	printf("MAX unsigned short: %u\n", us);
	printf("MIN unsigned short: %u\n\n", ust);

	// signed long
	signed long sl = 0, slt = 1;
	while (slt > 0) {
		sl = sl + 1;
		slt = sl + 1;
	}
	printf("MAX signed long: %ld\n", sl);
	printf("MIN signed long: %ld\n\n", slt);

	// unsigned long
	unsigned long ul = 0, ult = 1;
	while (ult > 0) {
		ul = ul + 1;
		ult = ul + 1;
	}
	printf("MAX unsigned long: %u\n", ul);
	printf("MIN unsigned long: %u\n\n", ult);
	getch();
	return 0;
}