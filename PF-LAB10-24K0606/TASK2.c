#include<stdio.h>
void per_splitter(float x,float i){
	if(i>100){
	return ;
	}
	printf("%.2f percent = %.2f \n",i,(i/100)*x);
	i++;
	per_splitter(x,i);
}
int main()
{
	float per,i;
	printf("Enter A Value To Split In Percetage : ");
	scanf("%f",&per);
	per_splitter(per,i);
}
