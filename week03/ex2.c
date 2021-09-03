#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *array, const int sz)
{
    for(int i = 0; i < sz; ++i){
        for(int j = i + 1; j < sz; ++j){
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    int sz;
    printf("Enter size of array: ");
    scanf("%d", &sz);
    
    int *array = (int*)malloc(sizeof(int) * sz);
    printf("Fill a array: ");
    for(int i = 0; i < sz; ++i)
    {
        scanf("%d", &array[i]);
    }
    
    bubble_sort(array, sz);
    printf("Sorted array: ");
    for(int i = 0; i < sz; ++i)
    {
        printf("%d ", array[i]);
    }

    return 0;
}