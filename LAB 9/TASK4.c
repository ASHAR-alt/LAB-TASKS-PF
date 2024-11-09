#include<stdio.h>
#include<string.h>
int main()
{
	char namelist[5][15]={"Ashar","Ali","Umar","Adnan","Asim"};
	char name[15];
	int count=0;
	printf("Enter Name : \n");
	scanf("%s",name);
	for(int i=0 ; i<5 ; i++){
		if(strcmp(namelist[i],name)==0){
			count=1;
			break;
	}}
	if(count==1){
		printf("Found");
	}else{
		printf("Not Found");
	}
	


return 0;
}

