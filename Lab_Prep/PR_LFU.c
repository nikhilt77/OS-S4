#include<stdio.h>

int main(){
    int n,max_fr;
    printf("Enter length of Ref. string:");
    scanf("%d",&n);
    printf("Enter no. of frames:");
    scanf("%d",&max_fr);
    int Frame[max_fr],Pages[n],Freq[n],Time[max_fr],hits=0,faults=0;
    printf("Enter ref. string:");
    for(int i=0;i<n;i++){
        scanf("%d",&Pages[i]);
    }
    for(int i=0;i<max_fr;i++){
        Frame[i]=-1;
        Freq[i]=0;
        Time[i]=0;
    }
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<max_fr;j++){
            if(Frame[j]==Pages[i]){
                found=1;
                hits++;
                Freq[j]++;
                Time[j]++;
                break;
            }
        }
        if(found!=1){
            if(i<max_fr){
                Frame[i]=Pages[i];
                Time[i]++;
                Freq[i]=1;
            }
            else{
                int min=0;
                for(int j=1;j<max_fr;j++){
                    if(Freq[min]>Freq[j]||(Freq[min]==Freq[j]&&Time[min]>Time[j])){
                        min=j;
                    }
                }
                Frame[min]=Pages[i];
                Freq[min]=1;
                Time[min]++;
                printf("%d loaded into farme %d\n",Pages[i],min);
            }
            faults++;
        }
        for(int i=0;i<max_fr;i++){
            if(Frame[i]!=-1){
                printf("%d\t",Frame[i]);
            }
            else{
                printf("_\t");
            }
        }
        printf("\n");
    }
    printf("Total Faults:%d\n",faults);
    printf("Total Hits:%d\n",hits);
    float fr=(float)faults/(faults+hits);
    printf("Fault Ratio:%.2f\n",fr);
}
