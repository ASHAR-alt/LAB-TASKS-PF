#include<stdio.h>
int main()
{
	int num,count,a=0,b=1,x;
	printf("Enter A Number :\n");
	scanf("%d",&num);
	if(num<=1){
		printf("It is Not A Prime Number\n\n");
	}else{
	for(int i=1 ; i<=num ; i++){
		if(num%i==0){
			count++;}
	}
	if(count==2){
		printf("It is A prime Number\n\n");
	}else{
		printf("It is Not A prime Number\n\n");
   }
} 
printf("Fibonacci Series Of %d Terms :\n",num);
   for(int j=1 ; j<=num ;j++){
   	printf(" %d  ",a);
   	x=a+b;
   	a=b;
   	b=x;}
	return 0;
}

