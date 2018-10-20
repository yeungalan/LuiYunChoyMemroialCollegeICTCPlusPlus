#include <stdio.h>
int main(){
	char ch;
	printf("Select and type a character from (a,b,c,d,q) then <ENTER>.\n");
	printf("'q' for normal quit : ");
	scanf("%c",&ch);
	switch(ch){
		case 'a':
			printf("Wanted character <a> typed.");
			break;
		case 'b':
			printf("Wanted character <b> typed.");
			break;
		case 'c':
			printf("Wanted character <c> typed.");
			break;
		case 'd':
			printf("Wanted character <d> typed.");
			break;
		case 'q':
			printf("Normal QUIT. Bye.");
			break;
		default:
			printf("UNWANTED character <%c> typed",ch);		
	}
	return 0;
}
