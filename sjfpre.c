#include <stdio.h>

typedef struct process
{
    int pid, at, bt, ct, tt, wt, rt;
} pro;

int temp[10];

void sortat(pro p[], int n)
{
    pro t;
    int tp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;

                tp = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = tp;
            }
        }
    }
}

void waittime(pro p[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        p[i].wt = p[i].tt - temp[i];
        p[i].rt = p[i].wt;
    }
}

void turnaroundtime(pro p[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        p[i].tt = p[i].ct - p[i].at;
    }
}

void schedule(pro p[], int n)
{
    int m = 0, min = 0, time = p[0].at, i = -1, j, completed = 0;
    int pid[30], ctime[30], len = 0;
    pid[0] = 0;

    while (completed != n)
    {
        m = 999;
        for (j = 0; j < n; j++)
        {
            if ((p[j].at > time) || (p[j].bt == 0))
                continue;
            if (m > p[j].bt)
            {
                min = j;
                m = p[min].bt;
            }
        }
        p[min].bt = p[min].bt - 1;
        p[min].ct = time + 1;
        if (p[min].pid != pid[i])
        {
            i++;
            len++;
        }
        pid[i] = p[min].pid;
        ctime[i] = p[min].ct;
        // len++;

        if (p[min].bt == 0)
            completed++;
        time++;
    }

    printf("\nGantt chart:\n");
    for (int i = 0; i < len; i++)
        printf("=======");
    printf("\n");
    for (int i = 0; i < len; i++)
        printf("  P%d  |", pid[i]);
    printf("\n");
    for (int i = 0; i < len; i++)
        printf("=======");
    printf("\n");
    printf("%d",p[0].at);
    for (int i = 0; i < len; i++)
        printf("     %d", ctime[i]);
    printf("\n\n");
}

void avgtime(pro p[], int n)
{
    int totalwt = 0, totaltat = 0, i;
    schedule(p, n);
    turnaroundtime(p, n);
    waittime(p, n);
    printf("pid\tAT\tBT\tCT\tWT\tTT\n");
    for (i = 0; i < n; i++)
    {
        totalwt += p[i].wt;
        totaltat += p[i].tt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, temp[i], p[i].ct, p[i].wt, p[i].tt);
    }
    printf("Avg wt=%f\n", (float)totalwt / (float)n);
    printf("Avg tt=%f\n", (float)totaltat / (float)n);
}

void main()
{
    pro p[10];
    int n, i;
    printf("Enter the number of processes\n");
    scanf("%d", &n);
    printf("Enter pid, at,and burst time\n");
    for (i = 0; i < n; i++)
    {

        scanf("%d %d %d", &p[i].pid, &p[i].at, &p[i].bt);
        temp[i] = p[i].bt;
    }
    printf("hi\n");
    sortat(p, n);
    avgtime(p, n);
}

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct process
// {
// 	int tt,wt,ct,at,bt,pid;
// }pro;
// int temp[10];

// void sortat(pro p[],int n)
// {
// 	int s;
// 	pro t;
// 	for(int i=0;i<n-1;i++)
// 	{
//		int flag=0;
// 		for(int j=0;j<n-i-1;j++)
// 		{
// 			if(p[j].bt>p[j+1].bt)
// 			{
//				flag=1;
// 				t=p[j];
// 				p[j]=p[j+1];
// 				p[j+1]=t;

// 				s=temp[j];
// 				temp[j]=temp[j+1];
// 				temp[j+1]=s;
// 			}
// 		}
// 	}
// }

// void waittime(pro p[],int n)
// {
// 	for(int i=0;i<n;i++)
// 		p[i].wt=p[i].tt-temp[i];
// }

// void ttime(pro p[],int n)
// {
// 	for(int i=0;i<n;i++)
// 		p[i].tt=p[i].ct-p[i].at;
// }

// void schedule(pro p[],int n)
// {
// 	int completed=0,min=0,pid[20],time=p[0].at,i=-1,len=0,ctime[20];
// 	pid[0]=0;
// 	while(completed!=n)
// 	{
// 		int m=999;
// 		for(int j=0;j<n;j++)
// 		{
// 			if(p[j].at>time || p[j].bt==0)
// 				continue;
// 			if(m>p[j].bt)
// 			{
// 				m=p[j].bt;
// 				min=j;
// 			}
// 		}
// 		p[min].bt=p[min].bt-1;
// 		p[min].ct=time+1;
// 		if(p[min].pid!=pid[i])
// 		{
// 			i++;
// 			len++;
// 		}
		
// 		pid[i]=p[min].pid;
// 		ctime[i]=p[min].ct;
// 		if(p[min].bt==0)
// 			completed++;
// 		time++;
// 	}

// 	printf("\nPrinting Ganttchart\n");
// 	for(i=0;i<len;i++)
// 	{
// 		printf(" ----");
// 	}
// 	printf("\n⎪");
// 	for(i=0;i<len;i++)
// 	{
// 		printf(" P%d ⎪",pid[i]);
// 	}
// 	printf("\n");
// 	for(i=0;i<len;i++)
// 	{
// 		printf(" ----");
// 	}
// 	printf("\n");
// 	printf("0");
// 	for(int i=0;i<len;i++)
// 		printf("   %2d",ctime[i]);
// 	printf("\n");
// }

// void calavg(pro p[],int n)
// {
// 	int totwt=0,avgwt,tottt=0,avgtt;
// 	sortat(p,n);
// 	schedule(p,n);
// 	ttime(p,n);
// 	waittime(p,n);
// 	printf("PID\t AT\t BT\t CT\t TT\t WT\n");
// 	for(int i=0;i<n;i++)
// 	{
// 		printf(" %2d\t %2d\t %2d\t %2d\t %2d\t %2d\n",p[i].pid,p[i].at,temp[i],p[i].ct,p[i].tt,p[i].wt);
// 		totwt+=p[i].wt;
// 		tottt+=p[i].tt;
// 	}
// 	printf("\nAverage turnaround time is %f\n",(float)tottt/(float)n);
// 	printf("Average waiting time is %f\n",(float)totwt/(float)n);	
// }

// int main()
// {
// 	int n;
// 	printf("Enter the number of processes\n");
// 	scanf("%d",&n);
// 	pro p[n];
// 	for(int i=0;i<n;i++)
// 	{
// 		printf("Enter AT and BT for process %d\n",i+1);
// 		scanf("%d%d",&p[i].at,&p[i].bt);
// 	}
// 	for(int i=0;i<n;i++)
// 	{
// 		p[i].pid=i+1;
// 		temp[i]=p[i].bt;
// 	}
// 	calavg(p,n);
// 	return 0;
// }






