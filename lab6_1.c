#include <stdio.h>
#include <stdlib.h>
void check(char,int,float);

int main(){
	/* declare */
	char ch;
	float num;
	int dnum;
	
	/* ask input */
	printf("Enter a character: ");
	scanf("%c",&ch);
	printf("Enter a integer: ");
	scanf("%d",&dnum);
	printf("Enter a floating point number: ");
	scanf("%f",&num);
	
	/* call function */
	check(ch,dnum,num);
	
	return 0;
}

void check(char ch,int dnum,float num){
	printf("\nThe ASCII value of a character <%c> is %d \n",ch,ch);
	printf("The integer is %d \n",dnum);
	printf("The floating point is %f \n",num);
}

