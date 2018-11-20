#include <stdio.h>
#include <string.h>
int secs(int hr,int min,int sec);
void secsRef(int hr,int min,int sec,int *totalsec);

int main(){
	int totala=0;
	int totalb;
	int hours,minutes,seconds;
	
	printf("Enter a number of hours: ");
	scanf("%d",&hours);
	printf("Enter a number of minutes: ");
	scanf("%d",&minutes);
	printf("Enter a number of seconds: ");
	scanf("%d",&seconds);
	
	totala= secs(hours,minutes,seconds);
	printf("The total number of seconds from function [secs] is %d\n\n",totala);
	secsRef(hours,minutes,seconds,&totalb);
	printf("The total number of seconds from function [secsRef] is %d",totalb);
	return 0;
}

int secs(int hr, int min, int sec){
	int totalsec = 0;
	totalsec = hr*3600 + min*60 + sec;
	return totalsec;
}


void secsRef(int hr, int min, int sec,int *totsec){
	*totsec = hr*3600 + min*60 + sec;
}
