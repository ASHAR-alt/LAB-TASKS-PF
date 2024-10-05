#include<stdio.h>
int main()
{
	int num,i=1;
	printf("Enter A Number\n");
	scanf("%d",&num);
	if(num<1){
		printf("Number should be greater or equal to 1");
	}
	else{
		while(i<=num){
			if(i%2==0){
				printf("%d\n",i);
			}
			i++;
		}
	}
}


