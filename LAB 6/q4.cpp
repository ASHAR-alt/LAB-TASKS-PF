#include<stdio.h>
int main()
{
	int num,sum;
	do{
		printf("Enter A Number :\n");
		scanf("%d",&num);
		if(num!=0){
			sum+=num;
		}
	}
	while(num!=0);
	printf("The Sum Is : %d", sum);
	return 0;
}


