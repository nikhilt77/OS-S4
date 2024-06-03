#include<stdio.h>
#define max 20
struct srtf{
    int AT;
    int BT;
    int pid;
    int WT;
    int RBT;
    int TAT;
}
p[max];
int main(){
    int totWT=0,totTAT=0,time=0,completed=0,shortest,n;
    printf("Enter no. of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the Burst time of P%d:",i);
        scanf("%d",&p[i].BT);
        printf("Enter the Arrival time of P%d:",i);
        scanf("%d",&p[i].AT);
        p[i].pid=i;
        p[i].RBT=p[i].BT;
        p[i].WT = 0;
        p[i].TAT = 0;
    }
    while(completed!=n){
        shortest=-1;
        for(int i=0;i<n;i++){
            if(p[i].RBT>0&&p[i].AT<=time){
                if(shortest==-1||p[i].RBT<p[shortest].RBT){
                    shortest=i;
                }
            }
        }
        if(shortest==-1){
            time++;
            continue;
        }
        p[shortest].RBT--;
        time++;
        if(p[shortest].RBT==0){
            p[shortest].TAT=time-p[shortest].AT;
            p[shortest].WT=p[shortest].TAT-p[shortest].BT;
            totTAT+=p[shortest].TAT;
            totWT+=p[shortest].WT;
            completed++;
        }
    }
    float avgTAT=(float)totTAT/n;
    float avgWT=(float)totWT/n;
    printf("    Process     BT       AT         WT        TAT     \n");
    for(int i=0;i<n;i++){
        printf("    %d          %d         %d         %d          %d      \n",p[i].pid,p[i].BT,p[i].AT,p[i].WT,p[i].TAT);
    }
    printf("Average WT:%.2f\n",avgWT);
    printf("Average TAT:%.2f\n",avgTAT);
    return 0;
}
