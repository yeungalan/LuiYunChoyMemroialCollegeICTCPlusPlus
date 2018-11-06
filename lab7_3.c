#include <stdio.h>
#include <stdlib.h>

/* construct Date */
struct Date{
	int year; 
	int month; 
	int day;
};
	
	
int main(){
	/* declare var */
	struct Date dte[3];
	int i;
	
	/* scan input */
	for(i=0;i<=2;i++){
		printf("Enter date <%d> with 3 numbers",i);
		scanf("%d %d %d",&dte[i].year,&dte[i].month,&dte[i].day);
	}
	
	/* print output */
	for(i=0;i<=2;i++){
		printf("The date <%d> is %d-%d-%d \n",i,dte[i].year,dte[i].month,dte[i].day);
	}
}
