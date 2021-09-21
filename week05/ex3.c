#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

const int size_buffer = 15;
int numbers[15];
int index = 0; // valid index
int sleepConsumer = 0, sleepProducer = 1;

void *Consumer(void *data)
{
    while (1)
    {   
        if (!sleepConsumer)
        {
            if (index != 0)
            {
                printf("Consume a number: %d\n", numbers[--index]);
            }
            else
            {
                printf("Consumed all numbers\n");
                sleepConsumer = 1;
                sleepProducer = 0;
            }
        }
    }
}

void *Producer(void *data)
{
    while (1)
    {
        if (!sleepProducer)
        {
            if (index != size_buffer)
            {
                numbers[index] = index;
                printf("Produce a number: %d\n", numbers[index++]);
            }
            else
            {
                printf("Produced all numbers\n");
                sleepProducer = 1;
                sleepConsumer = 0;
            }
        }
    }
}

int main()
{
    pthread_t threadProducer, threadConsumer;
    void *data;

    pthread_create(&threadProducer, NULL, Producer, data);
    pthread_create(&threadConsumer, NULL, Consumer, data);

    pthread_join(threadProducer, NULL);
    pthread_join(threadConsumer, NULL);

    return 0;
}