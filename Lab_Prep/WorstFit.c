#include<stdio.h>
int main(){
    int n,m,Worst;
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
        Worst=-1;
        for(int j=0;j<m;j++){
            if(Block[j]>=Process[i]){
                if(Worst==-1||Block[j]>Block[Worst]){
                    Worst=j;
                }
            }
        }
        if(Block[Worst]>=Process[i]){
            Allocation[i]=Worst;
            Block[Worst]-=Process[i];
        }
    }
    printf("\nProcess\tProcess_Size\tBlock\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t",i+1,Process[i]);
        if(Allocation[i]!=-1){
            printf("\t%d\n",Allocation[i]+1);
        }
        else{
            printf("\tNot Alloted\n");
        }
    }
}
