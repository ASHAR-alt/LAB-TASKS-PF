#include<stdio.h>
#include<string.h>
void message(char str[],int i,int l,char msg[]){
	if(i==l){
		printf("%s",msg);
		return;
	}
	msg[i]=str[l-1-i];
	i++;
	message(str,i,l,msg);
}
int main(){
	int i=0,l;
	char str[50],msg[50];
	printf("Enter A Sentence : ");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	l=strlen(str);
	message(str,i,l,msg);
}
