#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 81

/* declare dispstr */
void dispStr(char str[STRSIZE]);

int main(){
	/* declare var */
	char stringarray[STRSIZE];
	int i;
	
	/* input value */
	printf("Enter a string: ");
	gets(stringarray);
	 
	/* call function */
	dispStr(stringarray);
	
	return 0;
}

void dispStr(char str[]){
	/* declare var */
	int i=0;
	char chr;
	
	/* print value */
	printf("One word per line is:\n");
	/* if string not equal to EOL */
	while((chr = str[i]) != '\0'){
		/* if string not equal to space */
		if((chr = str[i]) == ' '){
			printf("\n");
		}else{
			printf("%c",chr);
		}
		/* iteration */
		i = i + 1;
	}
	
}
