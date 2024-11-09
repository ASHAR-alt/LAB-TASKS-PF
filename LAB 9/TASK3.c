#include<stdio.h>
#include<string.h>
int main(){
	char stored_username[]="admin";
	char stored_password[]="1234";
	char username[15] ;
	char password[15] ;
	printf("Enter Username : \n");
	scanf("%s",username);
	printf("Enter Password : \n");
	scanf("%s",password);
	if (strcmp(username,stored_username )==0 && strcmp(password,stored_password )==0 ){
		printf("Access Granted");		
	}else{	
		printf("Access Denied");
	}	
}
