#include<stdio.h>
int main()
{ 
  int i,j,k,n;
  printf("Enter Number Of Elements : ");
  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
  	for(j=i ; j>0 ; j--){
  		printf(" ");
	  }
	  for(k=n-i ; k>0 ; k--){
	  	printf("%d ",k);
	  }
	  printf("\n");
  }
  for(i=0 ; i<n-1 ;i++){
  	for(j=n-i-2 ; j>0 ; j-- ){
  		printf(" ");
	  }
	  for(k=i+2 ; k>0 ; k--){
	  	printf("%d ",k);
	  	
	  }
	  printf("\n");
  }

return 0;
}

