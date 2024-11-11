#include<stdio.h>
int main()
{
	int marks[4][4],i,j,k;
	for(i=0 ; i<4 ; i++){
		for(j=0 ; j<4 ; j++){
			printf("Enter Marks of Student%d Subject%d : ",i+1,j+1);
			scanf("%d",&marks[i][j]);
		}
	}printf("\n\nMarks Entered :\n\t");for(i=0 ; i<4 ; i++){
	printf("\tSubject%d",i+1);}printf("\n");
	for(i=0 ; i<4 ; i++){
		for(j=i ; j<=i ; j++){
			printf("Student%d\t",j+1);
		}
		for(k=0 ; k<4 ;k++){
			printf("  %d\t\t",marks[i][k]);
		}
		printf("\n");
	}
	for(i=0 ; i<4 ; i++){
		for(j=0 ; j<4 ; j++){
			if(marks[i][j]<0){
				marks[i][j]=0;
			}
		}	}
		printf("\n\nMarks After Correction : \n\t");
		for(i=0 ; i<4 ; i++){
	printf("\tSubject%d",i+1);}printf("\n");
	for(i=0 ; i<4 ; i++){
		for(j=i ; j<=i ; j++){
			printf("Student%d\t",j+1);
		}
		for(k=0 ; k<4 ;k++){
			printf("  %d\t\t",marks[i][k]);
		}
		printf("\n");
	}


return 0;
}

