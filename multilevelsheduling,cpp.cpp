#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int arrival_time,burst_time,Queue;
	int process_id;
}q;
int main()
{
	int size,quantum,done=0;
	int count=0;
	int time,smallest,waiting_time[50],turnaround_time[50],completion_time[50],temp_burst[50];
	double average_waiting_time,average_turnaround_time;
	printf("\nEnter the number of process");
	scanf("%d",&size);
	q no[size];
	for(int i=0;i<size;i++)
	{
		printf("\nProcess Id:\t");
		scanf("%d",&no[i].process_id);
		printf("Arrival Time:\t");
		scanf("%d",&no[i].arrival_time);
		printf("Burst Time:\t");
		scanf("%d",&no[i].burst_time);
		printf("Queue1/Queue2:\t");
		scanf("%d",&no[i].Queue);
	}
	printf("\nEnter the time quantum for Round Robin Schedulling:");
	scanf("%d",&quantum);
	for(int i=0;i<size;i++)
	{
		temp_burst[i]=no[i].burst_time;
	}
	no[size+1].burst_time=999;
	for(time=0;count!=size;time++)
	{
		smallest=size+1;
		for(int i=0;i<size;i++)
		{
		
		if(no[i].arrival_time<=time && no[i].burst_time<no[smallest].burst_time && no[i].burst_time>0 && no[i].Queue==1)
		{
			smallest=i;
		}
	}

	if(count>=size/2)
	{
		while(1)
		{
			for(int j=0;j<size;j++)
			{
				if(no[j].arrival_time<=time&&no[j].burst_time>quantum&&no[j].Queue==2)
				{
					no[j].burst_time-=quantum;
					smallest=j;
							}
							else if(no[j].arrival_time<=time&&no[j].burst_time<quantum&&no[j].Queue==2)
							{
								no[j].burst_time=0;
								smallest=j;
								goto a;
										}			}
		}
	}
	no[smallest].burst_time--;
	a:if(no[smallest].burst_time==0)
	{
		count++;
		completion_time[smallest]=time+1;
		turnaround_time[smallest]=completion_time[smallest]-no[smallest].arrival_time;
	     waiting_time[smallest] = turnaround_time[smallest] - temp_burst[smallest];
    }
}
   printf("\n\nProces id\tArrival time\t Burst time\t Waiting time\tTurnaround Time");
   for(int i=0;i<size;i++)
   {
   	 printf("\n   P%d   \t\t%d\t\t%d  \t\t%d\t\t%d",no[i].process_id,no[i].arrival_time,temp_burst[i],waiting_time[i],turnaround_time[i]);
        average_waiting_time += waiting_time[i];
        average_turnaround_time += turnaround_time[i];
    }
    printf("\n\nAverage waiting time = %lf\n",average_waiting_time/size);
    printf("Average Turnaround time = %lf",average_turnaround_time/size);

}
   


