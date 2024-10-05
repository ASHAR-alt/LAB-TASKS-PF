#include<stdio.h>
int main()
{
	int num,count;
	printf("Enter A Number :\n");
	scanf("%d",&num);
	if(num<=1){
		printf("It is Not A Prime Number");
	}else{
	for(int i=1 ; i<=num ; i++){
		if(num%i==0){
			count++;}
	}
	if(count==2){
		printf("It is A prime Number\n");
	}else{
		printf("It is Not A prime Number\n");
	}
} 
	return 0;
} 

