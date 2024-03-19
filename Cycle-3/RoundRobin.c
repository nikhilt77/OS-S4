#include <stdio.h>

struct process{
	int pid;
	int wtime;
	int ttime;
	int btime;
	int occur;
};

void main(){
	int totaltime = 0;
	float twaittime = 0;
	int timeslice = 0;
	int timeslicekeeper = 0;
	int timeslicekeeperkeeper = 0;
	int n;
	int currentproc = 0;
	printf("Enter number of process : ");
	scanf("%d",&n);
	printf("Enter timeslice : ");
	scanf("%d",&timeslice);
	timeslicekeeperkeeper = timeslice ;
	struct process p[n];

	for(int i=0 ; i<n ; i++){
		printf("Process %d data\n" , i+1);
		printf("Enter burst time :");
		scanf("%d",&p[i].btime);
		p[i].pid = i+1;
		timeslicekeeper += p[i].btime;
		p[i].occur = 0;
	}
	
	for(int i=0 ; i<timeslicekeeper ; i++){
	      if((timeslicekeeperkeeper % timeslice == 0 && i != 0)){
	            currentproc = (currentproc + 1)%n;
	            timeslicekeeperkeeper = timeslice ;
	      }
            while(p[currentproc].btime == 0){
                  currentproc = (currentproc + 1)%n;
                  timeslicekeeperkeeper = timeslice ;
            }
            p[currentproc].occur ++ ;
	      totaltime++;
	      p[currentproc].btime--;
	      printf(" %d ",p[currentproc].pid);
	      timeslicekeeperkeeper--;    
	}
	printf("\n");
	for(int i=0 ; i<timeslicekeeper ; i++){
	    printf(" %d ",p[i%n].occur - (timeslice - p[i%n].occur%timeslice));  
	}
	printf("\n");
}
