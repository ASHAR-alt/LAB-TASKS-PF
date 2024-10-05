#include<stdio.h>
int main()
{
	int num;
	do{
		printf("Enter A Number\n");
        scanf("%d",&num);
        if(num<=0)
        {
        	printf("NO!\n");
		}
	}
	while(num<=0);
	printf("HELL YEAH!");	
}
