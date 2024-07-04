#include<stdio.h>
#include<stdlib.h>
int main(){
    int initial,tot_head=0,n;
    printf("Enter no. of Requests:");
    scanf("%d",&n);
    printf("Enter Initial Head Position:");
    scanf("%d",&initial);
    int RQ[n];
    printf("Enter the Requests:");
    for(int i=0;i<n;i++){
        scanf("%d",&RQ[i]);
    }
    for(int i=0;i<n;i++){
        tot_head+=abs(initial-RQ[i]);
        initial=RQ[i];
    }
    printf("Total no. of head movements:%d",tot_head);
}
