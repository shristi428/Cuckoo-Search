#include <stdio.h>
#include <stdlib.h>

int population size=50;
int MXDOMAIN=500;
int MINDOMAIN= -500;
float lambda=1.5;
float pa=0.25;
float step_size=0.01;
int CMAX=0;//Minimising the makespan
int n=0;//No. of jobs
int m=0;//No.of Machines.
int i,j,k;
int T[i][j];//Having stating time on machine.
int P[i][j];//Having processing time on machine.
int X[i][j][k];//Boolean matrix .
int gen=0;//level of generation.
int Iteration=3000;


int Process_time(int m,int n){

for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        scanf("%d\n",&P[i][j]);
    }
}
retrun P;

}
//benchmark function= sphere function
int Objective_function(int p[i][j]){
    //generating fesiable solution eggs;
}



int Levy_flight(int ){
    //use to generate new candidate solution(eggs);
}

int Replacement_function(int )
{//set of individual eggs are probabilistically selected and replace.

}

int Elitist_function(int ,int ){
    //new value must be compared with its past value.

}
int main()
{
printf("Enter the number of jobs\n");
scanf("%d",&n);
printf("Enter the number of machines\n");
scanf("%d",&m);
printf("Enter the processing time of each time \n");
Process_time(m,n);

Objective_function( P[i][j]);
 while(/*stopping condtion*/){
 //cuckoo search algorithm implementation here.

}
