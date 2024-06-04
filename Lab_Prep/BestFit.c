#include<stdio.h>
int main(){
    int n,m,Best;
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
        Best=-1;
        for(int j=0;j<m;j++){
            if(Block[j]>=Process[i]){
            if(Block[j]<Block[Best]||Best==-1){
                Best=j;
            }
            }
        }
        if(Best!=-1){
            Allocation[i]=Best;
            Block[Best]-=Process[i];
        }
    }
    printf("\nProcess \tProcess Size \tBlock\n");
        for (int i = 0; i < n; i++) {
            printf("%d \t\t%d \t\t", i + 1, Process[i]);
            if (Allocation[i] != -1) {
                printf("%d\n", Allocation[i] + 1);
            } else {
                printf("Not allocated\n");
            }
        }

}
