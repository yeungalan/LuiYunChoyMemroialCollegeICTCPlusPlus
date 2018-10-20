#include <stdio.h>
int main(){
	float x,y;
	printf("Enter two floating point numbers:");
	scanf("%f %f",&x,&y);
	printf("The numbers you entered are %.1f %.1f\n",x,y);
	if(x==y){
		printf("%f is euqal to %f",x,y);
	}else if(x>y){
		printf("%.1f is greater to %.1f",x,y);
	}else{
		printf("%.1f is less than %.1f",x,y);
	}
	return 0;
}
