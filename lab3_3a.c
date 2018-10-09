#include <stdio.h>
#include <math.h>

int main(){
	/* declare variables */
	float x1,x2,y1,y2,distance;
	
	/* hardcode the coord into program */
	x1 = 7;
	y1 = 12;
	
	x2 = 3;
	y2 = 9;
	
	distance = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2)); //calc the distance
	printf("The distance between the two points is %f.\n",distance); //print the distance
	
	return 0;
}
