/*
	SJF
	By:- 
		SK Upadhyay
*/

#include<stdio.h>
struct data
{
	char name;
	char burst;
}d[50];
main()
	{
		FILE *f;
		int i,j, count=0,swap,swapname,name=1;
		char buf;	
		f=fopen("CPU_BRUST.txt","r");
		while ((buf=fgetc(f))!=EOF)
			{
				if(isspace(buf)||buf==' '||buf=='\n')
				{
					count++;
				}
			}
		printf("\t*****************************************");
		printf("\n\t|    PROCESS\t \t   BURST TIME\t|\n");
		fclose(f);
		f=fopen("CPU_BRUST.txt","r");
		for(i=0;i<count;i++)
		{
			fscanf(f,"%d",&d[i].burst);					//Reading BURST_TIME from FILE
			d[i].name=name;
			printf("\t|\tP%d", d[i].name);					//Generating Process Name-> P1,P2,.......
			printf("\t\t\t%d\t|",d[i].burst);
			printf("\n");
			name++;
		}
		printf("\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		for(i=0;i<count;i++)
		{
			if(d[i].burst<0)
			{
				printf("\n Invalid input");
				printf("\n Kindly Fix your Burst time in input file CPU_BRUST.txt");
				exit(0);
			}
		}
		for(i=0;i<count;i++)
		{
			for(j=i;j<count;j++)
			{
				if(d[i].burst>d[j].burst)				//Shorting Processes
				{
					swap=d[i].burst; 	
					d[i].burst=d[j].burst;
					d[j].burst=swap;
					swapname=d[i].name;
					d[i].name=d[j].name;
					d[j].name=swapname;
				}
			}
		}
		
		printf("\n\nShorting Process according to their BURST_TIME to perform SJF");
		printf("\n\t*****************************************");
		printf("\n\t|    PROCESS\t \t   BURST TIME\t|\n");
		for(i=0;i<count;i++)
		{
			printf("\t|\tP%d\t\t\t%d\t|\n",d[i].name,d[i].burst);
		}
		printf("\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");	
	}
