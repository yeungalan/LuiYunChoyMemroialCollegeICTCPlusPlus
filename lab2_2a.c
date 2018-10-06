#include <stdio.h>
int main(){
	// Arithmetic Sequences
	//  n
	// --- (2a+(n-1)d)
	//  2
	float sum;
	int n,a,d;
	sum = 0;
	n = 200;
	a = 1;
	d = 1;
	sum = (n)*(2*a+(n-1)*d)/2;
	printf("The sum the numbers from %d to %d is %f\n",a,n+a-1,sum);
	
	return 0;
}
