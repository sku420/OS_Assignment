/*
	SJF
	SK Upadhyay
*/

#include<stdio.h>
#include<ctype.h>
struct data
{
	char name;
	char burst;
}d[50];
main()
	{
		FILE *f;
		int i=0, count=0;
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
			d[i].name=i;
			printf("\t|\tP%d", d[i].name);				//Generating Process Name-> P0,P1,.......
			printf("\t\t\t%d\t|",d[i].burst);
			printf("\n");
		}
		printf("\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		for(i=0;i<count;i++)
		{
			if(d[i].burst<0)
			{
				printf("\n Invalid input");
			}
		}
		
	}
