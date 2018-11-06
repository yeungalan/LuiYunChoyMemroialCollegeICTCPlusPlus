#include <stdio.h>
#include <stdlib.h>

#define MAXROW 2
#define MAXCOL 4
#define ARRLENG 8

int main(){
	/* declare the var over here */
	/*   ____|___________ ROWS 
		     |
		     |
		COLUMN
	*/
	int my2DArr[MAXROW][MAXCOL] = {1,12,23,0,-1,-12,-23,289};
	int myArr[ARRLENG];
	int i = 0;
	int j = 0;
	
	/* print the 2x4 matrix here */
	printf("The data in my2DArr are: \n");
	for(i=0;i<=1;i++){
		for(j=0;j<=3;j++){
			printf("%5d",my2DArr[i][j]);
		}
		printf("\n");
	}
	
	/* ask for input integer into myArr*/
	printf("Enter 8 integers for my Arr:");
	for(i=0;i<=7;i++){
		scanf("%d",&myArr[i]);
	}
	
	/* print myArr */
	printf("The user-input data in myArr are: \n");
	for(i=0;i<=7;i++){
		printf("%d ",myArr[i]);
	}
	
	return 0;
	
}





