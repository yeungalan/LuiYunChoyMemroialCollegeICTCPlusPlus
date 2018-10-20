#include <stdio.h>
int main(){
	char ch;
	do{
		fflush(stdin);
		printf("Please input a character and then <Enter>, 'q' for exit.");
		scanf("%c",&ch);
		printf("The character you typed is [%c]\n",ch);
	}while (ch != 'q' && ch != 'Q');
	printf("The program quits, as you want...");
	return 0;
}
