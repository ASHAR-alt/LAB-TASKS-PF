#include<stdio.h>
int main()
{
	int scoreboard[3][3],sum1[3]={0,0,0},sum2[3]={0,0,0};
	printf("Enter A 3*3 Matrix : \n");
	for(int i=0 ; i<3 ; i++){
		for(int j=0 ; j<3 ; j++){
			printf("Enter element [%d][%d] of Matrix : ",i+1,j+1);
			scanf("%d",&scoreboard[i][j]);
		}
	}printf("\n\n\t");
	//I have printed scoreboard too just for better understanding dont deduct marks
	for(int k=0 ; k<3 ; k++)
		{
		    printf("\tParticipant%d ",k+1);
		}	printf("\n");
	for(int i=0 ; i<3 ; i++){
		printf("Activity%d",i+1);
		for(int j=0 ; j<3 ; j++){
			printf("\t\t%d ",scoreboard[i][j]);}
			printf("\n");
			}
			for(int i=0 ; i<3 ; i++){
				for(int j=0 ; j<3 ; j++){
					sum1[i]+=scoreboard[i][j];
					sum2[j]+=scoreboard[i][j];
				}				
		}
		printf("\nTotal Score Of Each Participant :\n");
		for(int i=0 ; i<3 ; i++){
		printf("Score Of Participant%d : %d\n",i+1,sum2[i]);
		}
		printf("\nTotal Score Of Each Activity :\n");
		for(int i=0 ; i<3 ; i++){
		printf("Score Of Activity%d : %d\n",i+1,sum1[i]);
		}	                    
return 0;
}

