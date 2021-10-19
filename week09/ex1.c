#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int page;
    int age;
} Frame;

Frame * frames;
int page;
long long int hit = 0, miss = 0;
int numberFrames;
void func()
{
    for (int i = 0; i < numberFrames; ++i)
    {
        if (frames[i].page == page)
        {
            frames[i].age |= (1 << 7);
            ++hit;
            return;
        }
    }

    // It miss
    int minIndex = -1;
    for (int i = 0; i < numberFrames; ++i) {
        if(frames[i].page == -1) {
            minIndex = i;
        }
    }

    if (minIndex == -1)
    {
        minIndex = 0;
        for(int i = 0; i < numberFrames; ++i) {
            if (frames[i].age < frames[minIndex].age) {
                minIndex = i;
            }
        }
    }
    frames[minIndex].age = 1 << 7;
    frames[minIndex].page = page;

    miss++;
}


int main()
{

    printf("Enter of number of frames: ");
    scanf("%d", &numberFrames);

    frames = (Frame *)malloc(sizeof(Frame) * numberFrames);
    for (int i = 0; i < numberFrames; ++i)
    {
        frames[i].age = 0;
        frames[i].page = -1;
    }

    freopen("input.txt", "r", stdin);
    while (scanf("%d", &page) == 1)
    {
        func();
        for(int i = 0; i < numberFrames; ++i)
        {
            frames[i].age >>= 1;
        }
    }

    printf("Hit: %lld\nMiss: %lld\nHit/Miss ratio: %f\n", hit, miss, (float)hit / (float)miss);
}