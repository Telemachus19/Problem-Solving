#include <stdio.h>
#include <math.h>

int main()
{
    int run, nruns;
    double x, y;
    scanf("%d\n", &nruns);
    for (run = 1; run <= nruns; run++)
    {
        scanf("%lf\n", &x);
        y = 1.0 / x;
        printf("%.7lf", y);
    }
    return 0;
}