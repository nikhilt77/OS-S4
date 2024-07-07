#include<stdio.h>
#include<stdlib.h>
int main(){
    int tot_movements=0,initial,pos,size,n,direction;
    printf("Enter Disk Size:");
    scanf("%d",&size);
    printf("Enter Record Size:");
    scanf("%d",&n);
    int RQ[n+1];
    printf("Enter the records:");
    for(int i=0;i<n;i++){
        scanf("%d",&RQ[i]);
    }
    printf("Enter disk head position:");
    scanf("%d",&initial);
    printf("Enter direction(1-high,0-low):");
    scanf("%d",&direction);
    RQ[n]=initial;
    n++;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(RQ[j]>RQ[j+1]){
                int temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(RQ[i]==initial){
            pos=i;
            break;
        }
    }
    if(direction==1){
        for(int i=pos;i<n;i++){
            tot_movements+=abs(initial-RQ[i]);
            initial=RQ[i];
        }
        tot_movements+=abs(size-1-initial);
        initial=0;
        for(int i=0;i<pos;i++){
            tot_movements+=abs(initial-RQ[i]);
            initial=RQ[i];
        }
    }
    else{
        for(int i=pos;i>=0;i--){
            tot_movements+=abs(initial-RQ[i]);
            initial=RQ[i];
        }
        tot_movements+=abs(initial-0);
        initial=size-1;
        for(int i=n-1;i>pos;i--){
            tot_movements+=abs(initial-RQ[i]);
            initial=RQ[i];
        }
    }
    printf("Total movements:%d",tot_movements+(size-1));
}
