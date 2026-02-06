#include <stdio.h>
#include <string.h>

int main()
{
    char pn[10][10], t[10];
    int arr[10], bur[10], star[10], finish[10], tat[10], wt[10], n;
    int totwt = 0, tottat = 0;

    printf("Enter the number of processes (max 10):");
    scanf("%d", &n);
    if (n > 10 || n < 1) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter Process Name, Arrival Time and Burst Time for process %d: ", i+1);
        scanf("%s %d %d", pn[i], &arr[i], &bur[i]);
    }

    // Sort by arrival time (bubble sort, stable)
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
            {
                // Swap arrival
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                // Swap burst
                temp = bur[j];
                bur[j] = bur[j+1];
                bur[j+1] = temp;
                // Swap name
                strcpy(t, pn[j]);
                strcpy(pn[j], pn[j+1]);
                strcpy(pn[j+1], t);
            }

    // Calculate times
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            star[i] = arr[i];
        else
            star[i] = (finish[i-1] > arr[i]) ? finish[i-1] : arr[i]; // Handle idle time

        finish[i] = star[i] + bur[i];
        tat[i] = finish[i] - arr[i];
        wt[i] = star[i] - arr[i];
    }

    printf("\nProcessName\tArrivalTime\tBurstTime\tStartTime\tWaitTime\tTurnAroundTime\tFinishTime");
    printf("\n-----------\t-----------\t---------\t---------\t--------\t--------------\t----------");

    for (int i = 0; i < n; i++)
    {
        printf("\n%s\t\t%3d\t\t%3d\t\t%3d\t\t%3d\t\t%6d\t\t%6d",
               pn[i], arr[i], bur[i], star[i], wt[i], tat[i], finish[i]);
        totwt += wt[i];
        tottat += tat[i];
    }

    printf("\n\nAverage Waiting time: %.2f", (float)totwt / n);
    printf("\nAverage Turn Around Time: %.2f\n", (float)tottat / n);
    return 0;
}
