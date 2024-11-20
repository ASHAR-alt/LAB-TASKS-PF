#include<stdio.h>
#include<string.h>
void rev_str(char arr[],int i){
	if(i<0){
		return;
	}
	printf("%c",arr[i]);
	i--;
	rev_str(arr,i);
}
int main(){
	char str[100];
	printf("Enter A String : ");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	int size,i=1;
	size=strlen(str)-1;
	rev_str(str,size);
	
	
}
