#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int mutex=1,full=0,empty=10,x=0 ;
void Producer(){
	--mutex;
	x++;
	full++;
	empty--;
	printf("Produce produced process:%d\n",x);
	++mutex;
}
void Consumer(){
	--mutex;
	x--;
	full--;
	empty++;
	printf("Consumer has consumed Process\n");
	++mutex;
}
//#pragma omp critical
int main(){
	printf("1.Producer\n2.Consumer\n3.Exit\nEnter Your Choice\n");
	int n;
		while(true){
			scanf("%d",&n);
			switch(n){
				case 1:if((mutex==1)&&(empty!=0)){
						Producer();
					}
					else{
						printf("No slots Available\n");
					}
					break;
				case 2:if((mutex==1)&&(full!=0)){
						Consumer();
					}
					else{
						printf("Slots are Empty\n");
					}
					break;
				case 3:exit(0);
					break;
				}
		}
}
								
								
	
