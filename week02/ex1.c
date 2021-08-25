#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    printf("int_max: %d\nsizeof(int): %lu: \n\nfloat_max: %f\nsizeof(float): %lu\n\ndouble_max: %lf\nsizeof(double): %lu ", a, sizeof(a), b, sizeof(b), c, sizeof(c));
    return 0;
}