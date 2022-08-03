#include <stdio.h>

typedef struct process
{
    int pid, at, bt, tt, wt, ct, rt;
} pro;
int temp[10]; // storing BT here

void sortat(pro p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                pro t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;

                int a = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = a;
            }
        }
    }
}

void waittime(pro p[], int n)
{
    for (int i = 0; i < n; i++)
        p[i].wt = p[i].tt - temp[i];
}

void ttime(pro p[], int n)
{
    for (int i = 0; i < n; i++)
        p[i].tt = p[i].ct - p[i].at;
}

void schedule(pro p[], int n)
{
    int completed = 0, time = p[0].at, cur = 0, k = 0, m, ctime[20], pid[20], len = 0;
    pid[0] = 0;
    while (completed != n)
    {
        m = 999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at > time || p[i].bt == 0)
                continue;
            if (m > p[i].bt)
            {
                cur = i;
                m = p[i].bt;
            }
        }
        if (p[cur].rt == -1)
            p[cur].rt = time - p[cur].at;
        time++;
        p[cur].bt--;
        p[cur].ct = time;
        if (p[cur].pid != pid[k])
        {
            k++;
            len++;
        }
        pid[k] = p[cur].pid;
        ctime[k] = time;
        if (p[cur].bt == 0)
            completed++;
    }

    printf("\n=============GANTTCHART=============\n");
    for (int i = 1; i <= len; i++)
        printf(" ----");
    printf("\n|");
    for (int i = 1; i <= len; i++)
        printf(" P%d |", pid[i]);
    printf("\n");
    for (int i = 1; i <= len; i++)
        printf(" ----");
    printf("\n");
    printf("%d", p[0].at);
    for (int i = 1; i <= len; i++)
        printf("   %2d", ctime[i]);
    printf("\n");
}

void calavg(pro p[], int n)
{
    int ttt = 0, twt = 0;
    sortat(p, n);
    schedule(p, n);
    ttime(p, n);
    waittime(p, n);
    printf("\nPID\tAT\tBT\tCT\tTT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, temp[i], p[i].ct, p[i].tt, p[i].wt, p[i].rt);
        ttt += p[i].tt;
        twt += p[i].wt;
    }
    printf("\nAverage TT is %f\n", (float)ttt / (float)n);
    printf("\nAverage WT is %f\n", (float)twt / (float)n);
}

int main()
{
    int n;
    printf("Enter the number of processes\n");
    scanf("%d", &n);
    pro p[n];
    printf("Enter the AT and BT for %d processes\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("P%d:", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].pid = i + 1;
        temp[i] = p[i].bt;
    }
    for (int i = 0; i < n; i++)
        p[i].rt = -1;
    calavg(p, n);
    return 0;
}