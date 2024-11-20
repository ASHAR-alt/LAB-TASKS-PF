#include<stdio.h>
void arr_printer(int arr[],int size,int i){
	if(i==size){
		return;
	}
	printf("\n%d ",arr[i]);
	i++;
	arr_printer(arr,size,i);
}
int main()
{
	int n;
	printf("Enter Size Of Array : ");
	scanf("%d",&n);
	int arr[n];	
	printf("Enter Array : \n");
	for(int i=0 ; i<n ; i++){
		scanf("%d",&arr[i]);
	}
	arr_printer(arr,n,0);
}
