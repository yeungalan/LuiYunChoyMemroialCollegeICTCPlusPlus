#include <stdio.h>
#include <stdlib.h>
int secs(int,int,int);

int main(){
	/* declare */
	int h,m,s,total;
	
	/* ask input */
	printf("\nEnter a number of hours: ");
	scanf("%d",&h);
	printf("\nEnter a number of minutes: ");
	scanf("%d",&m);
	printf("\nEnter a number of seconds: ");
	scanf("%d",&s);
	
	/* call function */
	total = secs(h,m,s);
	printf("\nThe total number of seconds from function [secs] is %d",total);
	
	return 0;
}

int secs(int h,int m,int s){
	int total;
	total = h*3600 + m*60 + s;
	return total;
}

