#include<stdio.h>
int main(){
    int n,m;
    printf("Enter no. of Processes:");
    scanf("%d",&n);
    printf("Enter no. of Blocks:");
    scanf("%d",&m);
    int Allocation[n],Block[m],Process[n];
    printf("Enter process sizes:");
    for(int i=0;i<n;i++){
        scanf("%d",&Process[i]);
    }
    printf("Enter Block sizes:");
    for(int i=0;i<m;i++){
        scanf("%d",&Block[i]);
    }
    for(int i=0;i<n;i++){
        Allocation[i]=-1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Allocation[i]==-1&&Block[j]>=Process[i]){
                Allocation[i]=j;
                Block[j]-=Process[i];
                break;
            }
        }
    }
    printf("Process\tProcess Size\tBlock\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t\t",i+1,Process[i]);
        if(Allocation[i]!=-1){
            printf("%d\n",Allocation[i]+1);
        }
        else{
            printf("Not allocated\n");
        }
    }
}
