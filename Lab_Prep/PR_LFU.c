#include<stdio.h>
#include<stdlib.h>
#define max_page 20
#define max_frames 3

struct F{
    int page;
    int frequency;
}
Frame[max_frames];
int completedtime=0;
void initialize(){
    for(int i=0;i<max_frames;i++){
        Frame[i].page=-1;
        Frame[i].frequency=0;
    }
}
void Display(){
    for(int i=0;i<max_frames;i++){
        if(Frame[i].page!=-1){
            printf("%d\t",Frame[i].page);
        }
        else{
            printf("_\t");
        }
    }
    printf("\n");
}
int find_LFU(){
    int minfreq=Frame[0].frequency;
    int minframe=0;
    for(int i=1;i<max_frames;i++){
        if(Frame[i].frequency<minfreq){
            minframe=i;
            minfreq=Frame[i].frequency;
        }
    }
    return minframe;
}
void LFU(int Pages[],int n){
    int faults=0,hits=0,found,refer;
    for(int i=0;i<n;i++){
        refer=Pages[i];
        found=0;
        for(int j=0;j<max_frames;j++){
            if(refer==Frame[j].page){
                found=1;
                hits++;
                Frame[j].frequency++;
                break;
            }
        }
        if(found==0){
            int LFU_frame=find_LFU();
            printf("Page %d replaced by %d\t", Frame[LFU_frame].page, refer);
            Frame[LFU_frame].page=refer;
            Frame[LFU_frame].frequency=1;//reset to 1
            faults++;
            printf("Page Fault No.%d\n",faults);
        }
        printf("Page %d\n",refer);
        Display();
    }
    float total=faults+hits;
    float fault_ratio=(float)faults/total;
    printf("Fault Ratio:%.2f\n",fault_ratio);
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
    LFU(Pages,n);
}
