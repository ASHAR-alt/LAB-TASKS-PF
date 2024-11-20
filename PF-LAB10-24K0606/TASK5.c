#include<stdio.h>
int sum_calc(int x,int sum)
  {
	if(x==0){
		printf("%d",sum);
		return sum;
	} 
	sum+=x%10;
	x/=10;
	sum_calc(x,sum);
	
}
int main(){
	int num,sum=0;
	printf("Enter A Number : ");
	scanf("%d",&num);
	sum_calc(num,sum);
	
	
}
