#include<stdio.h>
struct invoice{
	char part_num[20];
	char description[20];
	int quantity;
	float price_per_item;
};
int main()
{
    float invoice_amount;
	struct invoice items;
	printf("Enter Part Number : ");
	scanf("%s",items.part_num);
	printf("Enter Part description : ");
	scanf("%s",items.description);
	printf("Enter Part Quantity : ");
	scanf("%d",&items.quantity);
	printf("Enter Part Price : ");
	scanf("%f",&items.price_per_item);
	if(items.quantity<0){
		items.quantity=0;
	}
	if(items.price_per_item<0){
		items.price_per_item=0;
	}
	invoice_amount = items.quantity*items.price_per_item;
    printf("Total Price : %f",invoice_amount);
	return 0;
}
