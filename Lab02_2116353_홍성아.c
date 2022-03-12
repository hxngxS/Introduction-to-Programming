#include<stdio.h>

void strmul(char to[], char from[], int n) {
	int i;
	int j;
	int k;
	i = 0;

	for (k = 0; k < n; k++) {
		j = 0;
		while ((to[i] = from[j]) != '\0') {
			i++;
			j++;

		}
	}

}

void strsum(char to[], char from1[], char from2[]) {
	int i, j;

	i = 0;
	while ((to[i] = from1[i]) != '\0') {
		++i;
	}
	j = 0;
	while ((to[i] = from2[j]) != '\0') {
		i++;
		j++;
	}
}

main() {
	char s[100], t[100], u[100];

	strmul(t, "abc", 2);

	strmul(u, "DE", 3);

	strsum(s, t, u);

	printf("Ãâ·Â: %s\n", s);

	return 0;
}
