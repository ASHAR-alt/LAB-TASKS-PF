#include<stdio.h>
int main()
{
 int i, j, k, n;
 printf("Enter Number Of Elements : ");
 scanf("%d",&n);
 for(i=1 ; i<=n ; i++){
   for(j=n+1; j>=i ; j--){
   printf(". ");
   }
   for(k=0 ; k<i; k++){
   printf("o");
   }
   printf("\n");
   }
   for(i=1 ; i<=n+1 ; i++){
     for(j=0; j<i ;j++){
     printf(". ");
     }
     for(k=n+1 ; k>i-1 ; k--){
     printf("o");
     }
     printf("\n");
   }


}
