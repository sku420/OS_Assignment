/*
	Preemptive Priority
		By:-
			SK Upadhyay
*/


#include<stdio.h>
struct data
{
	int name;
	int burst;
	int arrival;
	int priority;
}d[100];

struct processdat
{
    int cburst;
    int rank;
    int burst;
    int status;
    int wait;
}p[100];

void printnow(int);
void print(int);
int Burst(int);
int shortBurst(int, int);
main()
{
	int i,j,n,swapburst,totalBurst,low;
	float avgw, avgt;
	printf("\n\t> Preemptive Priority Scheduler <");
	printf("\n\t> Data Input");
	printf("\n\t> Enter Total No. of Process:\t");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("\n\t> Enter Data For Process P%d", i+1);
		printf("\n\t> Enter Arrival Time:\t");
		scanf("%d", &d[i].arrival);
		printf("\n\t> Enter Burst Time:\t");
		scanf("%d", &d[i].burst);
		d[i].name=i+1;
		p[i].cburst=d[i].burst;
		p[i].burst=d[i].burst;

	}

	for(i=0;i<n;i++)							        //Shorting Process
    {
        for(j=i;j<n;j++)
        {
            if(p[i].cburst>p[j].cburst)
            {
                swapburst=p[i].cburst;
                p[i].cburst=p[j].cburst;
                p[j].cburst=swapburst;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        p[i].rank=i+1;
        p[i].status=0;
        p[i].wait=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(p[j].cburst==p[i].cburst)
            {
                p[j].rank=p[i].rank;
            }
        }
    }
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(d[i].burst==p[j].cburst)
			{
				d[i].priority=p[j].rank;
			}
		}
	}
	system("cls");
	print(n);
    totalBurst=Burst(n);
    for(i=0;i<totalBurst;i++)
    {
        low=shortBurst(n,i);
        p[low].burst=p[low].burst - 1;
        for (j=0;j<n;j++)
	  	{
	  	    if((low!=j)&&(d[j].arrival<=i)&&(p[j].status!=1))
            {
                p[j].wait=p[j].wait+1;
            }
        }
        if(p[low].burst==0)
        {
			p[low].status=1;
        }
    }
    printnow(n);
	 for (i=0;i<n;i++)
	  {
		avgw+=p[i].wait;
		avgt+=(p[i].wait+d[i].burst);
	  }
	 printf("\n\n\n \t Average Waiting Time : %0.2f",avgw/n);
	 printf("\n\n\n \t Average TurnAround Time : %0.2f\n\n",avgt/n);
}

void print(int n)
{
	int i;
	printf("\n\t\t\t\t-> Stored Data <-");
	printf("\n\t\t>-------------------------------------------------------<");
	printf("\n\t\t|\tPROCESS\t\tARRIVAL\t\tBURST\t\t|");
	for(i=0;i<n;i++)
	{
		printf("\n\t\t|\t  P%d\t\t   %d\t\t  %d\t\t|",d[i].name,d[i].arrival,d[i].burst);
	}
	printf("\n\t\t>-------------------------------------------------------<");
}

void printnow(int n)
{
	int i;
	printf("\n\t\t\t\t\t-> Processed Data <-");
	printf("\n\t>-----------------------------------------------------------------------<");
	printf("\n\t|\tPROCESS\t\tARRIVAL\t\tBURST\t\tPRIORITY\t|");
	for(i=0;i<n;i++)
	{
		printf("\n\t|\t  P%d\t\t   %d\t\t  %d\t\t   %d\t\t|",d[i].name,d[i].arrival,d[i].burst,d[i].priority);
	}
	printf("\n\t>-----------------------------------------------------------------------<");
}
int Burst(int n)
{
    int i,totalBurst=0;
    for (i=0;i<n;i++)
    {
        totalBurst=totalBurst+d[i].burst;
    }
    return totalBurst;
}
int shortBurst(int n,int excutedtime)
{
    int i,min,rtrn;
    min=10;
    for (i=0;i<n;i++)
    {
		if( (p[i].status!=1) && (d[i].priority<min) && (d[i].arrival<=excutedtime))
	 	{
			min=p[i].burst;
			rtrn=i;
	 	}
    }
    return rtrn;
}


