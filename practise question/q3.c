#include<stdio.h>
#include<string.h>
struct book{
	char  title[20];
	char author[20];
	int ISBN;
	int publication_year;
	char availabilty [15];	
};
void add_book(struct book books[],int *n){
	printf("Enter Details Of Book :\n\n");
	printf("Enter Book's Title \n");
	scanf("%s",books[*n].title);
	printf("Enter Book's Author \n");
	scanf("%s",books[*n].author);
	printf("Enter Book's ISBN \n");
	scanf("%d",&books[*n].ISBN);
	printf("Enter Book's Pulication Year \n");
	scanf("%d",&books[*n].publication_year);
	printf("Enter Book's Availabilty Status \n");
	scanf("%s",books[*n].availabilty);
	printf("\nBook Added Successfully !\n\n");
	(*n)++;
}
void search_book_byauthor(struct book books[] , int *n){
	char name[20];
	int found=0;
	printf("Enter Name Of Author :\n");
	scanf("%s",name);
	for(int i=0 ; i<(*n); i++){
		
		if(strcmp(name,books[i].author)==0){
			printf("Book found\n\n");
			found=1;
		}		
	}
	if(found==0){
			printf("Book not found\n\n");
	}	
	
}
void search_book_bytitle(struct book books[] , int *n){
	char name[20];
	int found=0;
	printf("Enter Book Title :\n");
	scanf("%s",name);
	for(int i=0 ; i<(*n); i++){
		
		if(strcmp(name,books[i].title)==0){
			printf("Book found\n\n");
			found=1;
		}		
	}
	if(found==0){
			printf("Book not found\n\n");
	}	
	
}
void check_out(struct book books[],int *n){
	int c,found=0;
	char name[20];
	printf("Enter 0 to return a book\n");
	printf("Enter 1 to check out book\n");
	scanf("%d",&c);
	if(c==0){
		printf("Enter Book Title : ");
		scanf("%s",name);
	for(int i=0 ; i<(*n); i++){		
		if(strcmp(name,books[i].title)==0){
		//	printf("Book found\n\n");
		strcpy(books[i].availabilty, "available");
		printf("\nBook Returned !\n");
			found=1;			
		}		
	}
	if(found==0){
			printf("Book not found\n\n");
	}
	}
	if(c==1){
		printf("Enter Book Title : ");
		scanf("%s",name);
	for(int i=0 ; i<(*n); i++){		
		if(strcmp(name,books[i].title)==0){
			strcpy(books[i].availabilty, "checked-out");
			printf("\nBook Checked-Out !\n");
			found=1;			
		}		
	}
	if(found==0){
			printf("Book not found\n\n");
	}
	}
		
}
int main(){
	struct book books[50];
	int x,n=0;
	while(1){
	printf("Press 1 to add book \n");
	printf("Press 2 to search a book by author name\n");
	printf("Press 3 to search a book by title name\n");
	printf("Press 4 to check out or return a book\n");
	printf("Press 5 to Exit \n");
    scanf("%d",&x);
	
	if(x==1){
		add_book(books , &n);
		//return;
	}
	if(x==2){
	     search_book_byauthor(books,&n);
		
	}
	if(x==3){
		search_book_bytitle(books,&n);
	}
	if(x==4){
		check_out(books,&n);
	}
	
	if(x==5){
		return 0;
	}
}
	
	
	return 0;
}
