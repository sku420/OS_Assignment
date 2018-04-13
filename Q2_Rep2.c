
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
struct dataprocess
{
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
	int i,j,n,swapburst, swapname, swaparrival;
	printf("\n\t> Preemptive Priority Scheduler<");
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
		//printf("\n\t> Enter Priority:\t");
		//scanf("%d", &d[i].priority);

	}
	for(i=0;i<n;i++)							        //Shorting Process
		{
			for(j=i;j<n;j++)
			{
				if(d[i].burst>d[j].burst)
				{
					swapburst=d[i].burst;
					d[i].burst=d[j].burst;
					d[j].burst=swapburst;
					swapname=d[i].name;
					d[i].name=d[j].name;
					d[j].name=swapname;
                    swaparrival=d[i].arrival;
                    d[i].arrival=d[j].arrival;
                    d[j].arrival=swaparrival;
				}
			}
		}
    for(i=0;i<n;i++)						
    {
        d[i].priority =i+1;
        p[i].status=0;
        p[i].wait=0;
        p[i].burst=d[i].burst;
    }
	system("cls");
	print(n);
}
void print(int n)
{
	int i;
	printf("\n\t\t\t\t-> Stored Data <-");
	printf("\n\t>-----------------------------------------------------------------------<");
	printf("\n\t|\tPROCESS\t\tARRIVAL\t\tBURST\t\tPRIORITY\t|");
	for(i=0;i<n;i++)
	{
		printf("\n\t|\t  P%d\t\t   %d\t\t  %d\t\t   %d\t\t|",d[i].name,d[i].arrival,d[i].burst,d[i].priority);
	}
	printf("\n\t>-----------------------------------------------------------------------<");
}
