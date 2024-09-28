#include<stdio.h>
int main()
{
	int amount, m_status;
	printf("Enter Total Purchase Amount\n");
	scanf("%d",&amount);
 	printf("Enter Membership Status :\nPress 1 for Membership\nPress 0  for No Membership\n");
	scanf("%d",&m_status);
	amount >100 && m_status==1 ? printf("You Are Eligible For Discount"):
    printf("You Are Not Eligible For A Discount");
    return 0;
}

