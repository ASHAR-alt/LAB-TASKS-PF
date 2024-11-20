#include<stdio.h>
struct flight{
	char pack_name[20];
	char destination[20];
	int duration;
	int cost;
	int seats_avail;
};
void book_pack(struct flight packages[],int *i){
	int seats_to_book=0;
	packages[*i].seats_avail=50;
	printf("Enter Package Name : ");
	scanf("%s",packages[*i].pack_name);
	printf("Enter Destination : ");
	scanf("%s",packages[*i].destination);
	printf("Enter Duration(in hours) : ");
	scanf("%d",&packages[*i].duration);
	printf("Enter Cost : ");
	scanf("%d",&packages[*i].cost);
	printf("Enter No. Of Seats To Book : ");
	scanf("%d",&seats_to_book);
	packages[*i].seats_avail-=seats_to_book;
	(*i)++;
	printf("\nFlight Booked Successfully!\n\n");	
}
void display_pack(struct flight packages[],int *i){
	if(*i==0){
	printf("No Packages Available");
	}else{
		for(int j=0 ; j<(*i) ; j++){
			printf("Package Name : %s\n",packages[j].pack_name);
			printf("Destination : %s\n",packages[j].destination);
			printf("Duration : %d\n",packages[j].duration);
			printf("Cost : %d\n",packages[j].cost);
			printf("Seats Available : %d\n\n",packages[j].seats_avail);
		}
	}
}
int main(){
	struct flight packages[20];
	int n,i=0;
	while(1){
		printf("Press 1 to Book A Package \n");
		printf("Press 2 to See Packages Available \n");
		printf("Press 3 to Exit \n");
		scanf("%d",&n);		
	
	if(n==1){
		book_pack(packages,&i);
	}
	if(n==2){
		display_pack(packages,&i);		
	}
	if(n==3){
		return 0;
	}	
}
}
