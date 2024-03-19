#include<stdio.h>
struct Process{
	int bt,wt,tt,pid;
}p;
void main(){

	int n,waitingtime,totaltime=0,twait;
	printf("Enter number of process:");
	scanf("%d",&n);
	struct Process p[n];
	for(int i=0;i<n;i++){
		printf("Enter burst time of Process%d: ",i);
		scanf("%d",&p[i].bt);
		p[i].pid=i+1;
		}
	for(int i=0;i<n;i++){
		p[i].wt=totaltime;
		totaltime+=p[i].bt;
		twait+=p[i].wt;
		p[i].tt=p[i].bt+p[i].wt;
		}
	printf("------------------------------------------\n");
	printf(" Process\t BT \t WT \t TT\n");
	for(int i=0;i<n;i++){
		printf(" %d\t\t%d \t %d \t %d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
		}
	printf("------------------------------------------\n");
	twait=twait/n;
	totaltime=totaltime/n;
	printf("Average Wait time:%d",twait);
	printf("Average TurnAround time:%d",totaltime);
	}
	
