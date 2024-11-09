#include<stdio.h>
int main()
{
	int price_bolt= 5 ,price_nut =3 ,price_washer = 1;
	int bolts , nuts , washers , total_cost;
	printf("Enter Number Of Bolts: \n");
	scanf("%d",&bolts);
	printf("Enter Number Of Nuts: \n");
	scanf("%d",&nuts);
	printf("Enter Number Of Washers: \n");
	scanf("%d",&washers);
	total_cost=((bolts*price_bolt)+(nuts*price_nut)+(washers*price_washer));
	printf("Check the Order:  ");
	if(nuts<bolts){
		printf("too few nuts\t");
	}
	if(washers<2*bolts){
		printf("too few washers");
	}
	if(bolts>=nuts && 2*washers>=bolts){
		printf("Order is OK");
	}
	printf("\nTotal Cost: %d",total_cost); 
return 0;
}

