#include<stdio.h>
void max_cuts(int l,int *count1,int *count2,int *count3){
	if(l==0){
		printf("MAX CUTS : %d",*count1+*count2+*count3);
		return;
	}
	if(l>=3){
		(*count3)++;
		max_cuts(l-3,count1,count2,count3);		
	}if(l==2){
		(*count2)++;
		max_cuts(l-2,count1,count2,count3);		
	} if(l==1){
		(*count1)++;
		max_cuts(l-1,count1,count2,count3)	;	
	}
	
}
int main(){
	int length,i=0, count1=0,count2=0,count3=0;
	printf("Enter Length Of Rope : ");
	scanf("%d",&length);
	max_cuts(length,&count1,&count2,&count3);
	
}

