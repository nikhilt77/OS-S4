#include<stdio.h>
#include<stdlib.h>
#define frame 3
#define pages 20
int Frame[frame];
int rear=-1;
void initialize(){
    for(int i=0;i<frame;i++){
        Frame[i]=-1;
    }
}
void Display(){
    for(int i=0;i<frame;i++){
        if(Frame[i]!=-1){
            printf("%d ",Frame[i]);
        }
        else{
            printf("_");
        }
    }
    printf("\n");
}
void FIFO(int Pages[],int n){
    int faults=0,hits=0,refer,found;
    for(int i=0;i<n;i++){
        found=0;
        refer=Pages[i];
        for(int j=0;j<frame;j++){
            if(refer==Frame[j]){
                found=1;
                hits++;
                break;
            }
        }
        if(!found){
            faults++;
            rear=(rear+1)%frame;
            Frame[rear]=Pages[i];
            printf("%d has been loaded into Frame%d",Pages[i],rear);
        }
        Display();
    }
    float fault_ratio=(float)faults/(faults+hits);
    printf("No. of Faults:%d",faults);
    printf("Fault ratio:%.2f",fault_ratio);
}
int main(){
    int n;
    printf("Enter length of reference string:");
    scanf("%d",&n);
    int Pages[n];
    printf("Enter reference string:");
    for(int i=0;i<n;i++){
        scanf("%d",&Pages[i]);
    }
    initialize();
    FIFO(Pages,n);   
}
