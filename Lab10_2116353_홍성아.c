#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>


int main(int argc, char*argv[]) 
{
        double integ(double a, double b, int n, double (*f)(double)); /* integrate y = f(x) */
        double* f(double);
        double lower, upper, val;
        int nsteps;

        if (argc <= 3) {
            printf("usage: integ sin/cos/tan lower-limit upper-limit [no-of-steps]");
        }
        nsteps = (argc == 4) ? 100 : atoi(argv[4]);
        lower = atof(argv[2]);
        upper = atof(argv[3]);
        if (strcmp(argv[1], "sin")==0)
            val = integ(lower, upper, nsteps, sin);
        else if (strcmp(argv[1], "cos")==0)
            val = integ(lower, upper, nsteps, cos);
        else if (strcmp(argv[1], "tan")==0)
            val = integ(lower, upper, nsteps, tan);
        else{ 
            printf("unrecognized trigonometric function name: %s\n", argv[1]);
            return 1;
        }
    printf("int_%g^%g %s(x) = %.3g with %d parts\n", lower, upper, argv[1], val, nsteps);
    return 0;
}

double integ(double a, double b, int n, double (*f)(double))
{
    double sum, x, x1, delta, area;
    int    i;

    delta = (b - a) / n;
    for (i = 0, sum = 0.0; i < n; i++) {
        x = a + i * delta;
        x1 = x + delta;
        area = delta * (f(x) + f(x1)) / 2;
        sum += area;
    }
    return sum;
}

