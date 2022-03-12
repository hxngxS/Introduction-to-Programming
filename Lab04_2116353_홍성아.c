#include<stdio.h>

int htoi(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= 'F'; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			n = n * 16 + (s[i] - '0');
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = n * 16 + (s[i] - 'A' + 10);
	}
	return n;
}

int main()
{
	printf("ABCDEF ==> %d\n", htoi("ABCDEF"));
	printf("123456 ==> %d\n", htoi("123456"));
	printf("0100 ==> %d\n", htoi("0100"));
}