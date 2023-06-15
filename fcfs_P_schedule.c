#include <stdio.h>
#include <conio.h>
#define max 30
int main()
{
    int i, j, n, bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time of the process: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("Process\t Burst time\t Waiting time\t Turn around time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] = bt[i - 1] + wt[i - 1];
        }
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("Average waiting time is: %f\n", awt);
    printf("Average Turn around time is: %f", atat);
    getch();
    return 0;
}


/*
Enter the number of processes: 4
Enter the burst time of the process: 21
3
6
2
Process  Burst time      Waiting time    Turn around time
1       21              0               21
2       3               21              24
3       6               24              30
4       2               30              32
Average waiting time is: 18.750000
Average Turn around time is: 26.750000

process priority doesn't matter.
Convoy Effect is a situation where many processes, who need to use a resource for short 
time are blocked by one process holding that resource for a long time.
the activity of the process manager that handles the removal of the running process from the CPU and the selection of .
TAT:CT-AT WT:TTAT-BT


*/