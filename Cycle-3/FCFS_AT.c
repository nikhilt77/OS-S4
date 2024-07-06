#include<stdio.h>
#define max 20

struct fcfs{
    int pid;
    int WT;
    int TAT;
    int BT;
    int AT;
    int CT;
}p[max];

int main(){
    int n,totTAT=0,totWT=0;
    printf("Enter no. of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Burst time of P%d:",i);
        scanf("%d",&p[i].BT);
        printf("Arrival time of P%d:",i);
        scanf("%d",&p[i].AT);
        p[i].pid=i;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].AT>p[j+1].AT){
                struct fcfs temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    int time=0;
    for(int i=0;i<n;i++){
        if(time<p[i].AT){
            time=p[i].AT;
        }
        p[i].CT=time+p[i].BT;
        p[i].TAT=p[i].CT-p[i].AT;
        p[i].WT=p[i].TAT-p[i].BT;
        time=p[i].CT;
        totTAT+=p[i].TAT;
        totWT+=p[i].WT;
    }
    float avgWT=(float)totWT/n;
    float avgTAT=(float)totTAT/n;
    printf("Process\tBT\tAT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].BT,p[i].AT,p[i].WT,p[i].TAT);
    }
    printf("Avg TAT:%.2f",avgTAT);
    printf("Avg WT:%.2f",avgWT);
}
