#include <stdio.h>
#include <stdlib.h>

void read_data(float *base,float *height);
void calculate_area(float,float,float *area);
int main(){
	float base,height,area;
	read_data(&base,&height);
	calculate_area(base,height,&area);
	
	printf("Area of the triangle with base %.2f and height %.2f is %.2f",base,height,area);
	return 0;
}

void read_data(float *base,float *height){
	float b,h;
	printf("Enter the base of the tirangle:");
	scanf("%f",&b);
	printf("Enter the height of the tirangle:");
	scanf("%f",&h);
	
	*base = b;
	*height = h;
}

void calculate_area(float base,float height,float *area){
	*area = (0.5)*base*height;
}


