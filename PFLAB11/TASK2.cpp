#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
int line_num = 1;
char line[100];
FILE *file;
file = fopen("test.txt","r");
if((file = fopen("C:\\Users\\CBM\\Downloads\\test.txt","r"))==NULL){
	printf("Error\n");
	return 1;}
while(fgets(line,sizeof(line),file)!= NULL ){
     printf("%s",line);
	
}

	return 0;
}
