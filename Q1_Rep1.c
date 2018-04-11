/*
	SJF
	By:- 
		SK Upadhyay
*/

#include<stdio.h>
struct data												//STRUCTURE STORES PROCESS
{
	char name;
	char burst;
}d[50];

main()
	{
		FILE *f;
		int i,j, count=0,swapburst,swapname,tat,wt=0,twt=0;
		char buf;
		
			
		f=fopen("CPU_BRUST.txt","r");					//Counting Number of WORDS
		while ((buf=fgetc(f))!=EOF)
		{
			if(buf==' '||buf=='\n')
			{
				count++;
			}
		}
		
		
		printf("\n\t\t    >Input Processes<\n");
		printf("\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		printf("\n\t|    PROCESS\t \t   BURST TIME\t|\n");
		fclose(f);
		f=fopen("CPU_BRUST.txt","r");
		for(i=0;i<count;i++)
		{
			fscanf(f,"%d",&d[i].burst);					//Reading BURST_TIME from FILE
			d[i].name=i+1;
			printf("\t|\tP%d", d[i].name);				//Generating Process Name-> P1,P2,.......
			printf("\t\t\t%d\t|",d[i].burst);
			printf("\n");
		}
		printf("\t_________________________________________");
		
		
		for(i=0;i<count;i++)							//Validating BURST_TIME
		{
			if(d[i].burst<0)
			{
				printf("\n\n\t-> Invalid Burst Time as: %d ", d[i].burst);
				printf("\n\t-> Kindly Fix your Burst time in input file CPU_BRUST.txt");
				exit(0);
			}
		}
		
		
		for(i=0;i<count;i++)							//Shorting Process
		{
			for(j=i;j<count;j++)
			{
				if(d[i].burst>d[j].burst)
				{
					swapburst=d[i].burst; 	
					d[i].burst=d[j].burst;
					d[j].burst=swapburst;
					swapname=d[i].name;
					d[i].name=d[j].name;
					d[j].name=swapname;
				}
			}
		}
		
		
		printf("\n\n=> Shorting Process according to their BURST_TIME to perform SJF");
		printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		printf("\n\t|    PROCESS\t \t   BURST TIME\t|\n");
		for(i=0;i<count;i++)
		{
			printf("\t|\tP%d\t\t\t%d\t|\n",d[i].name,d[i].burst);		//Printing Shorted Process
		}
		printf("\t_________________________________________");
		
		printf("\n\t\tWT\t\tTAT\n");
		for(i=0;i<count;i++)											//Calculating TAT and WT
		{
			tat=d[i].burst+wt;
			printf("\t\t%d\t\t%d\n", wt, tat);
			avgt+=tat;
			avgw+=wt;
			wt=wt+d[i].burst;
		}				
	}
