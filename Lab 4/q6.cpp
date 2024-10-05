#include<stdio.h>
int main()
{
	int x,y;
	printf("Enter First Number : \n");
	scanf("%d",&x);
	printf("Enter Second Number : \n");
	scanf("%d",&y);
	if (x>y){
		if(x>100){
			printf("First Number is Significantly Larger");
		}
		else{
			printf("First Number is Larger");
		}
	}
	else if(x<y)
		{
		  printf("First Number is smaller or negative");
		}
	else{
		  printf("Both Numbers Are Equal");
		}
	}
	


