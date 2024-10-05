#include<stdio.h>
int main()
{
	int fac=1 , num;
	printf("Enter A Number\n");
	scanf("%d",&num);
	if(num<0){
		printf("Number Is Negative");
	}
	else{
		for(int i=1 ;i<=num ; i++ ){
			fac*=i;
		}
		printf("The factorial of the number %d is : %d",num,fac);
	}
}

