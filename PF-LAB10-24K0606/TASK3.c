#include<stdio.h>
struct dealership{
	char make[20];
	char model[20];
	int year;
	int price;
	char mileage[20];
};
void add_cars(struct dealership cars[],int *i ){
	printf("Enter Car Details : \n");
	printf("\nEnter Make : ");
	scanf("%s",cars[*i].make);
	printf("Enter Model : ");
	scanf("%s",cars[*i].model);
	printf("Enter Year : ");
	scanf("%d",&cars[*i].year);
	printf("Enter Price : ");
	scanf("%d",&cars[*i].price);
	printf("Enter Mileage : ");
	scanf("%s",&cars[*i].mileage);
	printf("Car Added Successfully !\n\n");
	(*i)++;
}
void display_car(struct dealership cars[] , int *i){
	if(*i==0){
		printf("No Car Added !\n\n");
	}else{
		for(int j=0 ; j<(*i) ; j++){
			printf("%s\n",cars[j].model);
		}		
}
}

void search_by_model(struct dealership cars[],int *i){
	char name[15];
	int found=0;
printf("Enter Car Name : \n");	
scanf("%s",name);
for(int j=0 ; j<(*i);j++){
if(strcmp(cars[j].model,name)==0){
	printf("%s Found !\n\n",name);
	found=1;
}}
if(found==0){
		printf("%s Not Found !\n\n",name);
}	
}


void search_by_make(struct dealership cars[],int *i){
	char name2[15];
	int found=0;
printf("Enter Car Make : \n");	
scanf("%s",name2);
for(int j=0 ; j<(*i);j++){
if(strcmp(cars[j].make,name2)==0){
	printf("%s Found !\n\n",name2);
	found=1;
}}
if(found==0){
		printf("%s Not Found !\n\n",name2);
}	
}
	
int main(){
	struct dealership cars[20];
	int n,i=0;
	while(1){
	printf("Enter 1 to add cars \n");
	printf("Enter 2 to display cars available \n");
	printf("Enter 3 to search car by make \n");
	printf("Enter 4 to to search car by model \n");
	printf("Press 5 to Exit \n ");
	scanf("%d",&n);
	if(n==1){
		add_cars(cars,&i);
	}
	if(n==2){
		display_car(cars,&i);
	}
	if(n==4){
		search_by_model(cars,&i);
		
	}
	if(n==3){
		search_by_make(cars,&i);
		
		
	}
	if(n==5){
		return 0;
	}
}

}
