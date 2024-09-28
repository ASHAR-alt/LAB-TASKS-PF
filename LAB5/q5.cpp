#include<stdio.h>
int main()
{
	int num;
	printf("Enter A Number\n");
	scanf("%d",&num);
	if(num & 1){
		printf("Number Is Odd");
	}else{
	printf("Number Is Even");
	}
	return 0;
}

