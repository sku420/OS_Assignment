
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

void print(int);

main()
{
	int i,n;
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
		printf("\n\t> Enter Priority:\t");
		scanf("%d", &d[i].priority);
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
