#include <stdio.h>

void tr1(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 2 * i - 1; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
}

void tr2(int n)
{
    int x = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i + 1 - x; ++j)
        {
            printf("*");
        }
        if (i >= n / 2){
            x += 2;
        }
        printf("\n");
    }
    if (!(n % 2)){
        printf("*\n");
    }
}

void sqr(int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int n, size;
    printf("Enter two number: \na first number to choise a figure(triangular_first - 1, triangular_second - 2, squar - 3: ");
    scanf("%d", &n);
    printf("a second number of size of figure: ");
    scanf("%d", &size);
    if (n == 1)
    {
        tr1(size);
    }
    else if (n == 2)
    {
        tr2(size);
    }
    else if (n == 3)
    {
        sqr(size);
    }
}