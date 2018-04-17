#include <stdio.h>

void fcfs(int );				
void turn_around(int, int [], int []);		

int main()
{
	static int size;

	printf("Enter the total number of processes: ");
	scanf("%d", &size);

	if(size == 0)	goto empty_queue;	
	fcfs(size);			

	return 0;				

	empty_queue:	printf("\nProcess queue is empty. End of run.\n");
}

void fcfs(int size)
{
	int i, j, result;
	int arrival[size], burst[size], waiting[size];

	for(i=0; i<size; ++i)	waiting[i]=0;
	for(i=0; i<size; ++i) {
		printf("\nEnter arrival time for process %d : ", i+1);
		scanf("%d", &arrival[i]);

		printf("Enter burst time for process %d : ", i+1);
		scanf("%d", &burst[i]);
	}

	for(i=1; i<size; ++i) {
		result=0;
		for(j=0; j<i; ++j)	result+= burst[j];
		waiting[i]=result - arrival[i];	
	}


	printf("\nWaiting Time:\t");
	for(i=0; i<size; ++i)
		printf("%d\t", waiting[i]);

	
	for(i=0; i<size; ++i)	result+=waiting[i];
	
	result/=size;
	
	printf("\nAverage Waiting Time:\t%d", result);

	turn_around(size, burst, waiting);
	
	printf("\n");
}
void turn_around(int size, int burst[], int waiting[])
{
	int i;
	int turn_around_time[size];
	
	for(i=0; i<size; ++i)	
		turn_around_time[i]= burst[i] + waiting[i];

	printf("\nTurn Around Time:\t");
	for(i=0; i<size; ++i)	
		printf("%d\t", turn_around_time[i]);
}
