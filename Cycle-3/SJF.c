#include<stdio.h>
#define max 20
struct sjf{
     int AT;
     int BT;
     int CT;
     int TAT;
     int WT;
     int pid;
}p[max];

int main(){
    int n,completed=0,totWT=0,totTAT=0;
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
                struct sjf temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    int time=0;
    while(completed<n){
        int minbt=__INT_MAX__,pos=-1;
        for(int i=0;i<n;i++){
            if(p[i].BT<minbt&&p[i].AT<=time&&p[i].CT==0){
                minbt=p[i].BT;
                pos=i;
            }
        }
        if(pos==-1){
            time++;
        }
        else{
            p[pos].CT=time+p[pos].BT;
            p[pos].TAT=p[pos].CT-p[pos].AT;
            p[pos].WT=p[pos].TAT-p[pos].BT;
            time=p[pos].CT;
            totTAT+=p[pos].TAT;
            totWT+=p[pos].BT;
        }
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
