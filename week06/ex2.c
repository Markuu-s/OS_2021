#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Proccess
{
    int averageTime;
    int burstTime;

    int turnAroundTime;
    int waitingTime;
    int completionTime;

    int id;
};

void swap(struct Proccess *a, struct Proccess *b)
{
    struct Proccess temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int currentProccess;
    int countProcess;

    printf("Enter number of proccess: ");
    scanf("%d", &countProcess);

    struct Proccess *proccess = (struct Proccess *)malloc(countProcess * sizeof(struct Proccess));

    for (int i = 0; i < countProcess; ++i)
    {
        printf("Enter a average time of %d proccess: ", (i + 1));
        scanf("%d", &proccess[i].averageTime);

        printf("Enter a burst time of %d proccess: ", (i + 1));
        scanf("%d", &proccess[i].burstTime);

        proccess[i].id = i;
    }

    int currentTime = proccess[0].averageTime;
    int totalTAT = 0, totalWT = 0;
    int *boolExecuted = (int *)malloc(sizeof(int) * countProcess);


    for (int i = 0; i < countProcess; ++i)
    {
        int pos = 0, minBurstTime = INT_MAX;
        for(int j = 0; j < countProcess; ++j)
        {
            if (boolExecuted[j] == 0 && proccess[j].averageTime <= currentTime && proccess[j].burstTime < minBurstTime)
            {
                pos = j;
                minBurstTime = proccess[j].burstTime;
            }
        }
        boolExecuted[pos] = 1;

        currentTime += proccess[i].burstTime;
        if (proccess[i].averageTime > currentTime)
        {
            currentTime = proccess[i].averageTime;
        }
        proccess[i].completionTime = currentTime;

        proccess[i].turnAroundTime = currentTime - proccess[i].averageTime;
        proccess[i].waitingTime = proccess[i].turnAroundTime - proccess[i].burstTime;

        totalWT += proccess[i].waitingTime;
        totalTAT += proccess[i].turnAroundTime;
    }

    printf("\n#P\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < countProcess; ++i)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", proccess[i].id + 1,
               proccess[i].averageTime,
               proccess[i].burstTime,
               proccess[i].completionTime,
               proccess[i].turnAroundTime,
               proccess[i].waitingTime);
    }

    printf("\n\nAverage turn around time = %f\nAvarage waiting time = %f\n", (double)totalTAT / countProcess, (double)totalWT / countProcess);
}