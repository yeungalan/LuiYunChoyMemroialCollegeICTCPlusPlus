#include <stdio.h>
#include <math.h>

int main(){
	/* declare variables */
	float x1,x2,y1,y2,distance;
	
	printf("Enter 2 points x1, y1, x2 ,y2 in floating-point, separted with blank spaces: "); /* prompt message by printf */
	scanf("%f %f %f %f",&x1,&y1,&x2,&y2); /* input x1,y1.x2,y2 by scanf(); */
	distance = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));  /* calculate the distance by formula with sqrt() * pow()*/
	printf("The distance between the two points is %f.\n",distance); /* display distance in a variable */
}
