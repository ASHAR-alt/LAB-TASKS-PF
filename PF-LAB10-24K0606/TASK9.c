#include<stdio.h>
struct company{
	int emp_id;
	char emp_name[50];
	char dept_name[50];
	float salary; };
int main(){
	int num;
printf("Enter Number Of Employees : \n");
scanf("%d",&num);
struct company employees[20];
for(int i=0 ; i<num ; i++){
	printf("\nEnter Details Of Employee %d\n",i+1);
	printf("Enter Employee Id : ");
	scanf("%d",&employees[i].emp_id);
	printf("Enter Employee Name : ");
	scanf("%s",&employees[i].emp_name);
	printf("Enter Department Name : ");
	scanf("%s",&employees[i].dept_name);
	printf("Enter Salary : ");
	scanf("%f",&employees[i].salary); }
printf("\n\nEmployee Details :\n");
for(int i=0 ; i<num ; i++){
printf("Employee %d Details : \n",i+1);
printf("Employee Id : %d \n",employees[i].emp_id);
printf("Empeloyee Name : %s \n",employees[i].emp_name);
printf("Department Name : %s \n",employees[i].dept_name);
printf("Salary : %f\n",employees[i].salary);
} } 
