#include <stdio.h>
#include <math.h>

int main(){
	/* declare variables */
	float pi = 3.14159;
	float radius;
	float area;
	float sphere;
	
	printf("Enter the radius of a circle: "); //ask for radius
	scanf("%f",&radius); //input values into var radius
	printf("Pi is %.5f\n",pi); // print pi
	area = pi * pow(radius,2); // calc area
	printf("The area of the circle = %.2f \n",area); //show area
	sphere = 4 * pi * pow(radius,2); // calc sphere
	printf("The surface area of the circle = %.2f \n",sphere); // show surface area
	
	return 0;
}
