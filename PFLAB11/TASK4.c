#include<stdio.h> 
#include<string.h>
struct employee{
 char name[15];
 char dob[15]; 
 int emp_id; 
 char department[15]; 
 int salary;
};
void add_emp(struct employee data[], int *i){
	
  printf("Enter Name : ");
  scanf(" %s",data[*i].name); 
  printf("Enter Date Of Birth : "); 
  scanf(" %s",data[*i].dob);
  printf("Enter Employee Id : ");
  scanf("%d",&data[*i].emp_id);
  printf("Enter Department Name : ");
  scanf(" %s",data[*i].department);
  printf("Enter Salary : ");
  scanf("%d",&data[*i].salary);
  (*i)++;
  }

void delete_emp(struct employee data[] , int*i){
	char name[15];
	printf("Enter Employee Name To Delete Data\n");
	scanf("%s",name);
	for(int j=0 ; j<*i ; j++){
		if(strcmp(name,data[j].name)==0){
		for(int k=j ; k<*i ; k++){
			strcpy(data[k].name,data[k+1].name);
			strcpy(data[k].dob,data[k+1].dob);
			data[k].emp_id=data[k+1].emp_id;
			strcpy(data[k].department,data[k+1].department);
			data[k].salary=data[k+1].salary;
				}	
			printf("Employee Deleted\n");	
		 (*i)--;
		}			
	}	
}
int main()
{ 
int select,i=0,emp_count=1;;
  struct employee data[100];
    printf("EMPLOYEE MANAGEMENT SYSTEM");
 while(1){ 
  	printf("\nPress 1 to Add Employee \n");
	printf("Press 2 to Delete Employee \n");
	printf("Press 3 to Display All Employees \n");  
	printf("Press 4 to Exit \n"); 
	scanf("%d",&select); 
	if(select ==1){
 	add_emp(data,&i);
      }
         
  if(select==2){ 
      delete_emp(data,&i);
	
	}
    if(select==3)
	{ 
	if(i==0){
		printf("No Employees Added\n");
	}
	for(int j=0 ; j<i ; j++){
	  printf("\nEmployee %d :\n",j+1);
	  printf("%s\n",data[j].name);
	  printf("%s\n",data[j].dob);	
	  printf("%d\n",data[j].emp_id);
	  printf("%s\n",data[j].department);	
	  printf("%d\n",data[j].salary);
	} 	
	}
    if(select==4){ 
    return 0; }
 }
}

