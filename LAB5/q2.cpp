#include<stdio.h>
int main()
{
	int angle1,angle2,angle3;
	printf("Enter Three Angles Of A Triangle\n");
	scanf("%d %d %d",&angle1,&angle2,&angle3);
	if(angle1>0&&angle2>0&&angle3>0){
		if(angle1+angle2+angle3==180){
				printf("Triangle is Valid");
		}
		else{
		printf("Triangle is Not Valid");
	}
    }
	else{
		printf("Triangle is Not Valid");
	}
	return 0;
}
