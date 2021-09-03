#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *quickSort(int *array, int n)
{
    if (n <= 1)
    {
        return array;
    }

    int pivot = array[rand() % n];

    int left = 0;
    int right = 0;

    for (int i = 0; i < n; ++i)
    {
        if (array[i] <= pivot)
        {
            ++left;
        }
        else
        {
            ++right;
        }
    }

    if (left == 0 || right == 0)
    {
        int elem = array[0];
        int flag = 1;
        for (int i = 1; i < n; ++i)
        {
            if (array[i] != elem)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            return array;
        }
    }
    int *leftArray = (int *)malloc(sizeof(int) * left);
    int *rightArray = (int *)malloc(sizeof(int) * right);

    int idxLeft = 0;
    int idxRight = 0;
    for (int i = 0; i < n; ++i)
    {
        if (array[i] <= pivot)
        {
            leftArray[idxLeft++] = array[i];
        }
        else
        {
            rightArray[idxRight++] = array[i];
        }
    }

    leftArray = quickSort(leftArray, left);
    rightArray = quickSort(rightArray, right);

    idxLeft = 0;
    idxRight = 0;

    int *resArray = (int *)malloc(sizeof(int) * n);
    int idx = 0;
    while (idxLeft != left && idxRight != right)
    {
        if (leftArray[idxLeft] < rightArray[idxRight])
        {
            resArray[idx++] = leftArray[idxLeft++];
        }
        else
        {
            resArray[idx++] = rightArray[idxRight++];
        }
    }

    while (idxLeft != left)
    {
        resArray[idx++] = leftArray[idxLeft++];
    }

    while (idxRight != right)
    {
        resArray[idx++] = rightArray[idxRight++];
    }

    return resArray;
}

void print(int *array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{

    srand(time(NULL));

    int sz;
    printf("Enter size of array: ");
    scanf("%d", &sz);

    printf("Enter elements: ");
    int *array = (int *)malloc(sizeof(int) * sz);
    for (int i = 0; i < sz; ++i)
    {
        scanf("%d", &array[i]);
    }

    printf("\nUnsorted array: \n");
    print(array, sz);

    array = quickSort(array, sz);

    printf("\nSorted array: \n");
    print(array, sz);
}