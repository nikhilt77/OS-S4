#include<stdio.h>
#define max 20

struct pri{
    int AT;
    int TAT;
    int WT;
    int CT;
    int BT;
    int pid;
    int pri;
}p[max];

int main(){
    int n,totTAT=0,totWT=0,completed=0,time=0;
    printf("Enter n:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("BT AT PRI P%d:\n",i);
        scanf("%d %d %d",&p[i].BT,&p[i].AT,&p[i].pri);
        p[i].pid=i;
        p[i].CT=0;
    }
    while(completed<n){
        int min=-1;
        for(int i=0;i<n;i++){
            if(p[i].CT==0&&p[i].AT<=time){
                if(p[i].pri<p[min].pri||min==-1){
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
                time=p[min].CT;
                totTAT+=p[min].TAT;
                totWT+=p[min].WT;
                completed++;
            }

    }
    float avgTAT=(float)totTAT/n;
    float avgWT=(float)totWT/n;
    printf("P\tBT\tAT\tPr\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].BT,p[i].AT,p[i].pri,p[i].WT,p[i].TAT);
    }
    printf("Avg TAT:%.2f",avgTAT);
    printf("Avg Wt:%.2f",avgWT);
}
