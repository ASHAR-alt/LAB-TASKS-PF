#include<stdio.h>
int main()
{
	int per;
	printf("Enter Your Percentage\n");
	scanf("%d",&per);
	per>=90&&per<=100 ? printf("Your Grade is A\n") : 
	per>=80&&per<=89 ? printf("Your Grade is B\n") :
	per>=70&&per<=79 ? printf("Your Grade is C\n") :
	per>=60&&per<=69 ? printf("Your Grade is D\n") : printf("Your Grade is F\n");
	return 0;
}
