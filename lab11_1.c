#include <stdio.h>
#include <stdlib.h>

struct Record{
	char name[30]; 
	int number; 
	float salary;
};
	
int main(){
	struct Record employee[2];
	int i;
	for(i=0;i<2;i++){
		fflush(stdin);
		printf("Please enter the name of employee <%d>: ",i + 1);
		gets(employee[i].name);
		printf("Please enter the employee number: ");
		scanf("%d",&employee[i].number);
		printf("Please enter salary of employee: $");
		scanf("%f",&employee[i].salary);
		printf("\n");
	}
	
	for(i=0;i<2;i++){
		printf("Record of staff <%s> from ABC company:\n",employee[i].name);
		printf("*******************************\n");
		printf("Name of employee is: %s\n",employee[i].name);
		printf("Employee number is: %d\n",employee[i].number);
		printf("Salary of employee: %f\n\n",employee[i].salary);
	}
	
	return 0;
}
