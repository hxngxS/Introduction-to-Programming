#include<stdio.h>

main() {
	int p;
	char prime[1000];
	prime[0] = prime[1] = 0;
	for (p = 2; p < 1000; p++) {
		prime[p] = 1;
	}

	int n;
	for (p = 2; p*p < 1000; p++) {
		if (prime[p] == 1) {
			for (n = 2; n*p < 1000; n++) {
				prime[n*p] = 0;
			}
		}
	}

	int i = 0;
	for (p = 0; p < 1000; p++) {
		if (prime[p] == 1) {
			printf("%3d ", p);
			i++;
			if (i % 15 == 0)
				printf("\n");
		}
	}
	return 0;
}