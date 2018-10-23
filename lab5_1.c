#include <stdio.h>
int main(){
	char ch;
	do{
		fflush(stdin);														/* flush the stdin cache */
		printf("Please input a character and then <Enter>, 'q' for exit."); /* print the string */
		scanf("%c",&ch); 													/* ask user to input some value into ch */
		printf("The character you typed is [%c]\n",ch); 					/* display the value to user */
	}while (ch != 'q' && ch != 'Q');  										/* while statment which use for check if character is 'q' or 'Q' */
	printf("The program quits, as you want...");  							/* print the string */
	return 0; 
}
