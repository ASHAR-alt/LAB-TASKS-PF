#include<stdio.h>
int main()
{
	int num;
	printf("Enter Your Numbers : \n");
	scanf("%d",&num);
	if(num>=90 && num<=100)
	{
	printf("Your Grade is : A");
	}
	else if(num<=89 && num>=80) 
	{
	printf("Your Grade is : B");
	}
	else if (num<=79 && num>=70)
	{
	printf("Your Grade is : C");
	}
	else if (num<=69 && num>=60 )
	{
	printf("Your Grade is : D");
	}
	else
	{
	printf("Your Grade is : F");
	}
	return 0;
}