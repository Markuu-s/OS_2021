#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void *myRealloc(void *ptr, size_t newSize, size_t originSize)
{
    void *newPtr = malloc(newSize);
    if (ptr == NULL)
    {
        return newPtr;
    }

    if (newSize == 0)
    {
        free(ptr);
        free(newPtr);
        return NULL;
    }

    memcpy(newPtr, ptr, newSize < originSize ? newSize : originSize);
    free(ptr);
    return newPtr;
}

int main()
{
    int *a = (int*)malloc(sizeof(int) * 2);
    a[0] = a[1] = 5;
    printf("%d %d\n", a[0], a[1]);
    a = myRealloc(a, sizeof(int) * 4, sizeof(int) * 2);
    a[2] = a[3] = 100;
    printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
    a = myRealloc(a, sizeof(int), sizeof(int) * 4);
    printf("%d \n", a[0]);
    free(a);
}