#include<stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	int bitsA;
	bitsA = (x & ~0 << p + 1);

	int bitsC;
	bitsC = (x & ~(~0 << p - n + 1));

	int bitsE;
	bitsE = (y & ~(~0 << n));
	if (p > n) {
		bitsE = (y & (~(~0 << n))) << n;
	}

	return (bitsA | bitsE | bitsC);
}

main()
{
	printf("setbits(0X12345678, 7, 8, 0X89ABCDEF) = %X\n", setbits(0X12345678, 7, 8, 0X89ABCDEF));
	printf("setbits(0X12345678, 15, 16, 0X89ABCDEF) = %X\n", setbits(0X12345678, 15, 16, 0X89ABCDEF));
	printf("setbits(0X12345678, 15, 8, 0X89ABCDEF) = %X\n", setbits(0X12345678, 15, 8, 0X89ABCDEF));
	printf("setbits(0X12345678, 9, 10, 0X89ABCDEF) = %X\n", setbits(0X12345678, 9, 10, 0X89ABCDEF));
}

