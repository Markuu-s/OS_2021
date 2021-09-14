#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        fork();
        sleep(2);
    }

    return 0;
    
}