#include <stdio.h>
#include <stdlib.h>

int secs(int,int,int);
void secsRef(int,int,int,int *totsec);

int main(){
	/* declare */
	int h,m,s,totalsec,totsec;
	
	/* ask input */
	printf("Enter a number of hours: ");
	scanf("%d",&h);
	printf("Enter a number of minutes: ");
	scanf("%d",&m);
	printf("Enter a number of seconds: ");
	scanf("%d",&s);
	
	/* call function */
	totalsec = secs(h,m,s);
	printf("\nThe total number of seconds from function [secs] is %d\n",totalsec);
	
	secsRef(h,m,s,&totsec);
	printf("\nThe total number of seconds from function [secsRef] is %d",totsec);
	return 0;
}

int secs(int h,int m,int s){
	int totalsec;
	totalsec = h*3600 + m*60 + s;
	return totalsec;
}

void secsRef(int h,int m,int s,int *totsec){
	*totsec = h*3600 + m*60 + s;
}
