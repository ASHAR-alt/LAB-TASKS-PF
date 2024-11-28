#include<stdio.h>
struct phone{
	int area_code;
	int exc_code;
	int number;
};


int main(){
	struct phone my_phone={212 , 767 , 8900 };
    struct phone user_phone;
	printf("Enter Area Code : ");
	scanf("%d",&user_phone.area_code);
	printf("Enter Exchange Code : ");
	scanf("%d",&user_phone.exc_code);
	printf("Enter Phone Number : ");
	scanf("%d",&user_phone.number);
	printf("My Number is : (%d) %d-%d\n",my_phone.area_code,my_phone.exc_code,my_phone.number);
	printf("Your Number is : (%d) %d-%d",user_phone.area_code,user_phone.exc_code,user_phone.number);
	
	
}
