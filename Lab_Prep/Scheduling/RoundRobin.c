#include<stdio.h>
#define max 20
struct rr{
    int pid;
    int AT;
    int BT;
    int ts;
    int TAT;
    int WT;
    int RBT;
}
p[max];
int main(){
    int totWT=0,totTAT=0,completed=0,time=0,n,slice;
    printf("Enter no. of processes:");
    scanf("%d",&n);
    printf("Enter time quantum:");
    scanf("%d",&slice);
    for(int i=0;i<n;i++){
        printf("Enter Burst time of P%d:",i);
        scanf("%d",&p[i].BT);
        printf("Enter Arrival time of P%d:",i);
        scanf("%d",&p[i].AT);
        // p[i].ts=slice;
        p[i].pid=i;
        p[i].RBT=p[i].BT;
    }
    while(completed!=n){
        int flag=0;
        for(int i=0;i<n;i++){
        if(p[i].RBT>0&&p[i].AT<=time){
            flag=1;
            if(p[i].RBT<=slice){
                time+=p[i].RBT;
                p[i].RBT=0;
            }
            else{
                p[i].RBT-=slice;
                time+=slice;
            }
            if(p[i].RBT==0){
                p[i].TAT=time-p[i].AT;
                p[i].WT=p[i].TAT-p[i].BT;
                totTAT+=p[i].TAT;
                totWT+=p[i].WT;
                completed++;
            }
        }
        if(flag==0){
            time++;
        }
    }

}
    float avgWT=(float)totWT/n;
    float avgTAT=(float)totTAT/n;
    printf("\n");
    printf("=====================================\n");
    printf("Process\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].AT, p[i].BT, p[i].WT, p[i].TAT);
    }
    printf("Average Waiting time: %.2f\n", avgWT);
    printf("Average TAT: %.2f\n", avgTAT);
    return 0;
}
