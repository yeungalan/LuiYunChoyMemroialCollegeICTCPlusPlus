#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	/* declare var */
	char stringarray[40];
	int i;
	
	/* input values */
	printf("Please enter a string: ");
	gets(stringarray);
	 
	/* print values */
	for(i=strlen(stringarray) -1 ;i>=0;i--){
		printf("%c",stringarray[i]);
	}
	
	return 0;
}

