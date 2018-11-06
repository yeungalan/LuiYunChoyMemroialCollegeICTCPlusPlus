#include <stdio.h>
#include <stdlib.h>

#define MAXCOL 3
#define MAXROW 3

int main(){
	/* declare var */
	int first[MAXROW][MAXCOL] = {{1,2,3},{4,5,6},{8,9,10}};
	int second[MAXROW][MAXCOL] = {{9,8,7},{6,5,4},{3,2,4}};
	int sum[MAXROW][MAXCOL];
	int i,j;
	
	/*calc it */
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			sum[i][j] = first[i][j] + second[i][j];
		}
	}
	
	/* Print string*/
	printf("The sum of matrices of first and second are:\n");
	/* Print 3x3 Matrix */
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			printf("%5d",sum[i][j]);
		}
		printf("\n");
	}
}
