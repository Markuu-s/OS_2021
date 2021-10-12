#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>

#define szByte 10 * 1024 * 1024

int main()
{

    struct rusage useMemory;
    for (int i = 0; i < 10; ++i)
    {
        void *leakMemory = malloc(szByte);
        memset(leakMemory, 0, szByte);
        getrusage(RUSAGE_SELF, &useMemory);
        printf("Memory usage: %ld\n", useMemory.ru_maxrss);
        sleep(1);
    }
    return 0;
}
