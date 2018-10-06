#include <stdio.h>
int main(){
	// distance = speed * time
	// as 1 year convert to second = 60^2*24*365
	double speed = 300000000;
	double time = 60*60*24*365; 
	double sum = speed * time;

	printf("The total distance light travels in one year is %f meters.\n",sum);
		
	return 0;
}
