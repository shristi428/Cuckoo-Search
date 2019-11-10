#include<stdio.h>
#include<stdlib.h>

#define nests 10
#define max 15

int machines;
int jobs;
int tasks;
int machine_no;
int job_no;
int due_time; 
int process_time[max][max];
int Due_time[max][max];

int main(){
	int i,j;
	printf("Enter the number of machines\n");
	scanf("%d",&machines);
	printf("Enter the number of jobs\n");
	scanf("%d",&jobs);
	printf("Enter the number of total tasks\n");
	scanf("%d",&tasks);
	
	printf("enter the machine no.and job no.\n");
	for(i=0;i<tasks;i++){
		scanf("%d %d",&machine_no,&job_no);
		printf("enter the process_time \n");
		scanf("%d",&process_time[machine_no][job_no]);	
	}
	for(i=1;i<=machines;i++)
	{
		for(j=1;j<=jobs;j++)
		{
		 printf("%4d",process_time[i][j]);
		 
		}
		printf("\n");
		 	
	}
	disjunctive_graph(process_time,)
	
	return 0;
}
