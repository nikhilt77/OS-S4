#include<stdio.h>
#define max 20
struct sjf{
    int pid;
    int BT;
    int WT;
    int TAT;
}
p[max];
int main(){
    int totTAT=0,totWT=0,n;
    printf("Enter no. of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Burst time of P%d:",i);
        scanf("%d",&p[i].BT);
        p[i].pid=i;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].BT>p[j].BT){
                struct sjf temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    p[0].WT=0;
    p[0].TAT=p[0].BT;
    totTAT+=p[0].WT;
    totTAT+=p[0].TAT;
    for(int i=1;i<n;i++){
        p[i].WT=p[i-1].BT+p[i-1].WT;
        p[i].TAT=p[i].WT+p[i].BT;
        totTAT+=p[i].TAT;
        totWT+=p[i].WT;
    }
    float avgTAT=(float)totTAT/n;
    float avgWT=(float)totWT/n;
    printf("==================Gantt Chart==================\n");
    printf("    Process     BT       WT        TAT     \n");
    for(int i=0;i<n;i++){
        printf("    %d          %d          %d          %d      \n",i,p[i].BT,p[i].WT,p[i].TAT);
    }
    printf("Average WT:%.2f\n",avgWT);
    printf("Average TAT:%.2f\n",avgTAT);
    return 0;
}
