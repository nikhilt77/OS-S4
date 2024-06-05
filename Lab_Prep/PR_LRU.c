#include<stdio.h>
#include<stdlib.h>
#define max_frame 3
#define max_page 20
int completed_time=0;
struct F{
    int time;
    int page;
}Frame[max_frame];
void initialize(){
    for(int i=0;i<max_frame;i++){
        Frame[i].page=-1;
        Frame[i].time=0;
    }
}
void Display(){
    for(int i=0;i<max_frame;i++){
        if(Frame[i].page!=-1){
            printf("%d ",Frame[i].page);
        }
        else{
            printf("_");
        }
    }
    printf("\n");
}
int find_lru(){
    int mintime=Frame[0].time;
    int minframe=0;
    for(int i=1;i<max_frame;i++){
        if(Frame[i].time<mintime){
            mintime=Frame[i].time;
            minframe=i;
        }
    }
    return minframe;
}
void LRU(int Pages[],int n){
    int faults=0;
    int hits=0;
    for(int i=0;i<n;i++){
        int found=0;
        completed_time++;
        int refer=Pages[i];
        for(int j=0;j<max_frame;j++){
            if(refer==Frame[j].page){
                hits++;
                found=1;
                Frame[j].time=completed_time;
                break;
            }
        }
            if(found==0){
                int frame=find_lru();
                faults++;
                Frame[frame].page=refer;
                Frame[frame].time=completed_time;
                printf("Page %d placed at %d\t",refer,frame);
                printf("Page Fault No.%d\n",faults);
            }
            printf("Page %d:",i);
            Display();
        }
    float total=faults+hits;
    float fault_ratio=(float)faults/total;
    printf("Fault ratio:%.2f\n",fault_ratio);
}
int main(){
    int n;
    printf("Enter reference string length:");
    scanf("%d",&n);
    int Pages[n];
    printf("enter reference string:");
    for(int i=0;i<n;i++){
        scanf("%d",&Pages[i]);
    }
    initialize();
    LRU(Pages,n);
}
