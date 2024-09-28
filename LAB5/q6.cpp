#include<stdio.h>
int main()
{
	int num,ones=0;
	printf("Enter A Number :\n");
	scanf("%d",&num);
	while(num!=0)
	{
	  if(num&1){
	  	ones++;
	  }
	num = num >> 1; 
	}
	 printf("Number Of 1's : %d",ones);
	return 0;
}


