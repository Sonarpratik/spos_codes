// process scheduling Round Robin
#include <stdio.h>
#include <conio.h>
void main()
{
    int i, n, qt, count = 0, temp, sq = 0, bt[10], wt[10], tat[10], rem_bt[10];
    float awt = 0, atat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time of process: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
    printf("Enter Quantum time: ");
    scanf("%d", &qt);
    while (1)
    {
        for (i = 0, count = 0; i < n; i++)
        {
            temp = qt;
            if (rem_bt[i] == 0)
            {
                count++;
                continue;
            }
            if (rem_bt[i] > qt)
            {
                rem_bt[i] = rem_bt[i] - qt;
            }
            else if (rem_bt[i] >= 0)
            {
                temp = rem_bt[i];
                rem_bt[i] = 0;
            }
            sq = sq + temp;
            tat[i] = sq;
        }
        if (n == count)
            break;
    }
    printf("\nProcess\t\tBurst time\tTurn around time\t waiting time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("\n%d\t\t%d\t\t%d\t\t\t%d\n", i + 1, bt[i], tat[i], wt[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("Average waiting time is: %f\n", awt);
    printf("Average Turn around time is: %f", atat);
}
/*output
Enter the number of processes: 5
Enter burst time of process: 6
5
2
3
7
Enter Quantum time: 2

Process         Burst time      Turn around time         waiting time

1               6               19                      13

2               5               20                      15

3               2               6                       4

4               3               15                      12

5               7               23                      16
Average waiting time is: 12.000000
Average Turn around time is: 16.600000
--------------------------------
Process exited after 12.96 seconds with return value 38
Press any key to continue . . .*/
