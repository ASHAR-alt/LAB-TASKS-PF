#include<stdio.h>
void bubblesort(int arr[],int n,int i,int max){
	if(i==n){
		printf("\nERROR AFTER BUBBLE SORT : \n");
		for(int k=0 ; k<n ; k++){
			printf("%d ",arr[k]); 
		}
		return;
	}
	for(int j=0 ; j<n-1 ; j++){
		if(arr[j]<arr[j+1]){
			max=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=max;			
		}
	}
	i++;
	 bubblesort(arr,n,i,max);
	
}
int main(){
	int size,i=0,max=0;
	printf("Enter Size Of Array : \n");
	scanf("%d",&size);
	int arr[size];
	printf("Enter Array : \n");
	for(int i=0 ; i<size ; i++){
		scanf("%d",&arr[i]);
	}
	bubblesort(arr,size,i,max);
}
