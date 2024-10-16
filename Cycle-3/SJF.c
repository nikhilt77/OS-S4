#include<stdio.h>
#define max 20

struct sjf{
    int AT;
    int TAT;
    int WT;
    int BT;
    int CT;
    int pid;
}p[max];

int main(){
    int n,totTAT=0,totWT=0,time=0,completed=0;
    printf("Enter no. of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("BT AT P%d:",i);
        scanf("%d %d",&p[i].BT,&p[i].AT);
        p[i].pid=i;
        p[i].CT=0;
    }
    while(completed<n){
        int min=-1;

        for(int i=0;i<n;i++){
            if(p[i].CT==0&&p[i].AT<=time){
                if(p[i].BT<p[min].BT||min==-1){
                    min=i;
                }
            }
        }
        if(min==-1){
            time++;
        }
        else{
           p[min].CT=time+p[min].BT;
           p[min].TAT=p[min].CT-p[min].AT;
           p[min].WT=p[min].TAT-p[min].BT;
           totTAT+=p[min].TAT;
           totWT+=p[min].WT;
           time=p[min].CT;
           completed++;
        }
    }
    float avgTAT=(float)totTAT/n;
    float avgWT=(float)totWT/n;
    printf("P\tBT\tAT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].BT,p[i].AT,p[i].TAT,p[i].WT);
    }
    printf("AvgTAT:%.2f",avgTAT);
    printf("AvgWT:%.2f",avgWT);
}
