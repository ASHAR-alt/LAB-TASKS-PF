#include<stdio.h>
#include<math.h>
int main()
{
	int num,sum,x;
	printf("Enter A Number\n");
	scanf("%d",&num);
	x=num;
	while(num>0){
		sum+=pow(num%10,3);
		num/=10;
	}
	if(sum==x || x==1){
		printf("IT IS AN ARMSTONG NUMBER\n");
	}else{
		printf("IT IS NOT AN ARMSTONG NUMBER\n");
	}
	return 0;
}

