#include <stdio.h>

#define columnLen 3
#define rowsLen 5

void readArray(int *X)
{
    for(int i = 0; i < columnLen; ++i)
    {
        scanf("%d", &X[i]);
    }
}

void read2Array(int X[rowsLen][columnLen])
{
    for(int i = 0; i < rowsLen; ++i)
    {
        for(int j = 0; j < columnLen; ++j)
        {
            scanf("%d", &X[i][j]);
        }
    }
}

int check(const int *A, const int *R)
{
    for(int i = 0; i < columnLen; ++i)
    {
        if (A[i] < R[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char inputName[] = "input.txt";
    char outputName[] = "output.txt";

    freopen(inputName, "r", stdin);
    freopen(outputName, "w", stdout);

    int E[columnLen], A[columnLen], C[rowsLen][columnLen], R[rowsLen][columnLen];
    readArray(E);
    readArray(A);
    read2Array(C);
    read2Array(R);

    int unUse[rowsLen];

    for(int i = 0; i < rowsLen; ++i)
    {
        unUse[i] = 1;
    }

    for(int i = 0; i < rowsLen; ++i)
    {
        int flag = 1;
        for(int j = 0; j < rowsLen; ++j)
        {
            if (unUse[j] == 1 && check(A, R[j]) == 1)
            {
                flag = 0;
                unUse[j] = 0;
                for(int ioi = 0; ioi < columnLen; ++ioi)
                {
                    A[ioi] += C[i][ioi];
                }
            }
        }

        for(int j = 0; j < rowsLen; ++j)
        {
            if (unUse[j] != 0)
            {
                goto continueAlg;
            }
        }
        break;

    continueAlg: ;
        int count = 0;
        for(int j = 0; j < rowsLen; ++j)
        {
            count += unUse[j];
        }
        if (flag == 1)
        {
            printf("%d\n", count);
            return 0;
        }
    }
    printf("No deadlock");
    return 0;
}