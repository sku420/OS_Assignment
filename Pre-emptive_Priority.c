/*
	Pre-emptive Priority
		By:-
			SK Upadhyay
			K1643A22
*/


#include<stdio.h>
#include<malloc.h>

struct data										//Main Data
{
	int name;
	int burst;
	int arrival;
	int priority;
}d[100];

struct processdat								//Copied cum Additional Data
{
    int cburst;
    int rank;
    int burst;
    int status;
    int wait;
}p[100];

void printnow(int);
void print(int);
int  Burst(int);
int  shortBurst(int, int);
void ganttchart(int, int *);
void wait(int, int, int);
void priority(int, int);

main()
{
	int i,j,n,swapburst,totalBurst;
	float avgw, avgt;
	printf("\n\t> Preemptive Priority Scheduler <");
	printf("\n\n\t\t> Data Entry <");
	printf("\n\n\t> Enter Total No. of Process:\t");
	scanf("%d", &n);
	if(n==0)
	{
		printf("\n\t> There is no process input\n");
		return;
	}
	
	for(i=0;i<n;i++)
	{
		d[i].name=i;
		printf("\n\t> Enter Data For Process P%d", d[i].name);
		printf("\n\n\t> Enter Arrival Time:\t");
		scanf("%d", &d[i].arrival);
		printf("\n\t> Enter Burst Time:\t");
		scanf("%d", &d[i].burst);
		p[i].cburst=d[i].burst;
		p[i].burst=d[i].burst;
		p[i].status=0;
		p[i].wait=0;
	}
	
	for(i=0;i<n;i++)							        						//Arrival Validation
    {
        for(j=i+1;j<n;j++)
        {
            if(d[i].arrival==d[j].arrival||d[i].arrival<0 ||d[i].burst<0)
            {
                printf("\n\n\t-> Their are some processes having same arrival time");
                printf("\n\n\t-> or their are some -ve value of arrival or burst time\n\n");
            	return;
            }
        }
    }
    
	for(i=0;i<n;i++)															//Arrival time!=0
	{
		if (d[i].arrival==0)
		{
         	break;
      	}
   	}
   	if(i==n)
	{
		printf("\n\n\t> There is no process with arrival time = 0\n\n");

		return;
	}


	for(i=0;i<n;i++)							       							 //Shorting Process
    {
    	if(d[i].burst>0)
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
    	else
    	{
    		printf("\n\n\t> There is a process with burst time = 0\n\n");
			return;	
		}
    }
    for(i=0;i<n;i++)
    {
        p[i].rank=i+1;
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
    for(i=0;i<n;i++)																//Priority Assigning
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
    priority(n, totalBurst);
	 for (i=0;i<n;i++)
	  {
		avgw+=p[i].wait;
		avgt+=(p[i].wait+d[i].burst);
	  }
	 printf("\n\n\n \t Average Waiting Time : %0.2f",avgw/n);
	 printf("\n\n\n \t Average TurnAround Time : %0.2f\n\n",avgt/n);
}

void print(int n)																	//to Print Input Data
{
	int i;
	printf("\n\t\t\t\t\t-> Stored Data <-");
	printf("\n\t\t\t>-------------------------------------------------------<");
	printf("\n\t\t\t|\tPROCESS\t\tARRIVAL\t\tBURST\t\t|");
	for(i=0;i<n;i++)
	{
		printf("\n\t\t\t|\t  P%d\t\t   %d\t\t  %d\t\t|",d[i].name,d[i].arrival,d[i].burst);
	}
	printf("\n\t\t\t>-------------------------------------------------------<");
}

void printnow(int n)																//to Print Processed Data
{
	int i;
	printf("\n\n\t\t\t\t\t-> Processed Data <-");
	printf("\n\t\t>-----------------------------------------------------------------------<");
	printf("\n\t\t|\tPROCESS\t\tARRIVAL\t\tBURST\t\tPRIORITY\t|");
	for(i=0;i<n;i++)
	{
		printf("\n\t\t|\t  P%d\t\t   %d\t\t  %d\t\t   %d\t\t|",d[i].name,d[i].arrival,d[i].burst,d[i].priority);
	}
	printf("\n\t\t>-----------------------------------------------------------------------<");
}

int Burst(int n)																	//total Burst
{
    int i,totalBurst=0;
    for (i=0;i<n;i++)
    {
        totalBurst=totalBurst+d[i].burst;
    }
    return totalBurst;
}

void priority(int n, int tb)														//Priority Scheduling
{
	int i, low, *gantt;
	gantt=(int *)calloc(tb,sizeof(int));
	for(i=0;i<tb;i++)
    {
        low=shortBurst(n,i);
        p[low].burst=p[low].burst - 1;
        gantt[i]=low;
		wait(n,low,i);
        if(p[low].burst==0)
        {
			p[low].status=1;
        }
    }
    printnow(n);
	ganttchart(tb, gantt);	
}
void wait(int n, int low, int excuted)												//Wait Time
{
	int i;
	for (i=0;i<n;i++)
	{
  	    if((low!=i)&&(d[i].arrival<=excuted)&&(p[i].status!=1))
        {
            p[i].wait=p[i].wait+1;
        }
	}
}
int shortBurst(int n,int excutedtime)												//Shortest Job
{
    int i,min,rtrn;
    min=100;
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
void ganttchart(int n, int *gantt)													//To Print Gantt Chart
{
	int i;
	printf("\n\n\n\n-> Gantt Chart\n");
	for (i=0;i<n;i++)									//Process Name
	{
		if (i==0)
		 	printf("\n    P%d",gantt[i]);
		else
		{
		   	if (gantt[i]!=gantt[i-1])
			{
			  	printf("  P%d",gantt[i]);
			}
			else
			{
			  	printf("  ");
			}
		}
	}
 
	printf("\n    ");									//Box Creation
	for (i=0;i<n;i++)
	{
		if (i==0)
			printf("__");
		else
		{
			if (gantt[i]!=gantt[i-1])
			{
			  	printf("  __");
			}
		    else
			{
			  	printf("__");
			}
		}
	}
	printf("\n   |");
	for (i=0;i<n;i++)
	{
		if (i==0)
			printf("__");
		else
		{
		   if (gantt[i]!=gantt[i-1])
		   {
			  	printf("||__");
			}
		   else
		   {
			  	printf("__");
			}
		}
	}
	  printf("|");
 
	 printf("\n");										//Complition Cum Response Time
	 for (i=0;i<n;i++)
	 {
		if (i==0)
			printf("   0 ");
		else
		{
		   if (gantt[i]!=gantt[i-1])
		   {
			  	printf("% d  ",i);
			}
		   else
		   {
			  	printf("  ");
			}
		 }
	  }
	  printf("%d",n);	
}
