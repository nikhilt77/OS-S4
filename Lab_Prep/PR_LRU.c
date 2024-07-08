#include<stdio.h>
int main(){
    int n,max_fr,faults=0,hits=0;
    printf("Enter ref. string length:");
    scanf("%d",&n);
    printf("Enter frame size:");
    scanf("%d",&max_fr);
    int Frame[max_fr],RF[n],Time[n];
    printf("Enter string:");
    for(int i=0;i<n;i++){
        scanf("%d",&RF[i]);
    }
    for(int i=0;i<max_fr;i++){
        Frame[i]=-1;
        Time[i]=0;
    }
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<max_fr;j++){
            if(Frame[j]==RF[i]){
                hits++;
                Time[j]++;
                found=1;
                break;
            }
        }
        if(found!=1){
            faults++;
                int min=0;
                for(int j=1;j<max_fr;j++){
                    if(Time[min]>Time[j]){
                        min=j;
                    }
                }
                Frame[min]=RF[i];
                Time[min]++;
                printf("%d loaded into Frame %d\n",RF[i],min);
        }
        for(int k=0;k<max_fr;k++){
            if(Frame[k]!=-1){
                printf("%d\t",Frame[k]);
            }
            else{
                printf("_\t");
            }
        }
        printf("\n");
    }
    float fr=(float)faults/(hits+faults);
    printf("Page Faults:%d\n",faults);
    printf("Fault Ratio:%.2f\n",fr);
}
