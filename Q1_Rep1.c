/* 
	SJF   
	Rep. 1
	By:- SK Upadhyay
*/

#include<stdio.h>

struct data
{
	int burst;
}d[50];

void main()
	{
		FILE *f;
		int i, n=9;	
		f=fopen("CPU_BRUST.txt","r");
		printf("\t*******************************");
		printf("\n\t|  PROCESS\t   BURST TIME |\n");
		for(i=0;i<n;i++)
			{
				fscanf(f,"%d",&d[i].burst);				//Reading BURST_TIME from FILE
				printf("\t|    P%d", i);				//Generating Process Name-> P0,P1,.......
				printf("\t\t\t%d     |",d[i].burst);
				printf("\n");
			}
			printf("\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		for(i=0;i<n;i++)
			{
				if(d[i].burst<0)
					{
						printf("\n Invalid input");
						exit(0);
					}
			}
			fclose(f);
	}
