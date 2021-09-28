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

    int startBurstTime;

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

    int quantum;
    printf("Enter quantum: ");
    scanf("%d", &quantum);

    struct Proccess *proccess = (struct Proccess *)malloc(countProcess * sizeof(struct Proccess));

    for (int i = 0; i < countProcess; ++i)
    {
        printf("Enter a average time of %d proccess: ", (i + 1));
        scanf("%d", &proccess[i].averageTime);

        printf("Enter a burst time of %d proccess: ", (i + 1));
        scanf("%d", &proccess[i].burstTime);
        proccess[i].startBurstTime = proccess[i].burstTime;

        proccess[i].id = i;
    }

    int currentTime = proccess[0].averageTime;
    int finished = 0;
    int totalTAT = 0, totalWT = 0;
    int *boolExecuted = (int *)malloc(sizeof(int) * countProcess);

    int i = 0;
    while (finished != countProcess)
    {
        if (boolExecuted[i] == 1)
        {
            i = (i + 1) % countProcess;
        }

        if (proccess[i].burstTime <= quantum)
        {
            currentTime += proccess[i].burstTime;
            proccess[i].completionTime = currentTime;

            proccess[i].turnAroundTime = proccess[i].completionTime - proccess[i].averageTime;
            totalTAT += proccess[i].turnAroundTime;

            proccess[i].waitingTime = proccess[i].turnAroundTime - proccess[i].startBurstTime;
            totalWT += proccess[i].waitingTime;
            ++finished;
            boolExecuted[i] = 1;
            i = (i + 1) % countProcess;
        }
        else
        {
            currentTime += quantum;
            proccess[i].burstTime -= quantum;
            i = (i + 1) % countProcess;
        }
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