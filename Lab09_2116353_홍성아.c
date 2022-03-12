#include <stdio.h>
#include <ctype.h>
#define SIZE 100

main()
{
    int array[SIZE], n;
    int gethex(int*);
    int i, sum;

    for (n = 0; n < SIZE && gethex(&array[n]) != EOF; n++)
        ;
    sum = 0;
    for (i = 0; i < n; i++)
        sum += array[i];
    printf("The sum is %d\n", sum);
}

/* getint:  get next integer from input into *pn */
int gethex(int* pn)
{
    int c, sign;

    while (isspace(c = getchar()))   /* skip white space */
        ;
    if (!isxdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetc(c, stdin);  /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getchar();
    for (*pn = 0; isxdigit(c); c = getchar()) {
        if (c >= '0' && c <= '9')
            *pn = 16 * *pn + (c - '0');
        else if (c >= 'a' && c <= 'f')
            *pn = 16 * *pn + (c - 'a' + 10);
        else if (c >= 'A' && c <= 'F')
            *pn = 16 * *pn + (c - 'A' + 10);
    }

    *pn *= sign;
    if (c != EOF)
        ungetc(c, stdin);
    return c;
}