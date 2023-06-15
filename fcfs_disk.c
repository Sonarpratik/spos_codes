#include <stdio.h>
#include <stdlib.h>
int main()
{
    int rq[100], i, n, TotalHeadMoment = 0, initial;
    printf("Enter the number of Requests: \n");
    scanf("%d", &n);
    printf("Enter the request sequence:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &rq[i]);
    }
    printf("Enter initial head position: \n");
    scanf("%d", &initial);
    for (i = 0; i < n; i++)
    {
        TotalHeadMoment = TotalHeadMoment + abs(rq[i] - initial);
        initial = rq[i];
    }
    printf("Total head moment is %d", TotalHeadMoment);
    return 0;
}


/*
Enter the number of Requests:
4
Enter the request sequence:
45 21 67 90
Enter initial head position: 
50
Total head moment is 98
*/