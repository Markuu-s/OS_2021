#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

void *myThread(void *thread_data)
{
    printf("\n>> Hello from thread - %d!\n", *((int*)thread_data));
    pthread_exit(0);
}

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        pthread_t thread;
        int *thread_data = &i;
        if (pthread_create(&thread, NULL, myThread, thread_data))
        {
            printf(" >> ERROR IN CREATING Thread #!\n");
            pthread_exit(NULL);
            return 1;
        }
        else
        {
            printf("\n>> Thread #%d created!\n", i);
            pthread_join(thread, NULL);
        }
    }
}