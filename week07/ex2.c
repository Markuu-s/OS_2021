#include <stdlib.h>
#include <stdio.h>

int main()
{
    int N;
    printf("Enter size of array (N): ");
    scanf("%d", &N);

    int *array = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; ++i)
    {
        array[i] = i;
    }

    for(int i = 0; i < N; ++i)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }

    free(array);
    return 0;
}