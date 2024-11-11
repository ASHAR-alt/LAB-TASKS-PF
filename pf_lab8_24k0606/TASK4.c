#include<stdio.h>
int main()
{
	int m,n,i,j;
	printf("Enter Number Of Rows : \n");
	scanf("%d",&m);
	printf("Enter Number Of Columns : \n");
	scanf("%d",&n);
	int matrix1[m][n],matrix2[m][n],result_matrix[m][n];
	printf("Enter Elements Of Matrix 1 :\n");
	for(i=0;i<m;i++){
		for(j=0 ; j<n ; j++){
			printf("Enter Element[%d][%d] : ",i+1,j+1);
			scanf("%d",&matrix1[i][j]);
		}	
	}
	printf("\nEnter Elements Of Matrix 2 :\n");
	for(i=0;i<m;i++){
		for(j=0 ; j<n ; j++){
			printf("Enter Element[%d][%d] : ",i+1,j+1);
			scanf("%d",&matrix2[i][j]);
		}	
	}
	for(i=0;i<m;i++){
		for(j=0 ; j<n ; j++){
			result_matrix[i][j]=matrix1[i][j]+matrix2[i][j];
		}
	}
	printf("\nResultant Matrix : \n");
	for(i=0;i<m;i++){
		for(j=0 ; j<n ; j++){
			printf("%d ",result_matrix[i][j]);}
			printf("\n");}
	
return 0;
}

