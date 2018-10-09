#include <stdio.h>
int main(){
	/* declare variables in different data types */
	char ch;
	int num;
	float fnum;
	
	printf("Input a character, followed by <ENTER> key: "); /* prompt message by printf() */
	scanf("%c",&ch);										/* input a character by scanf()*/
	printf("Character <%c> is entered!\n",ch);				/* display input character on screen by printf()*/

	printf("Input a integer, followed by <ENTER> key: ");   /* prompt message by printf() */
	scanf("%d",&num);										/* input a integer by scanf()*/
	printf("Character <%d> is entered!\n",num);				/* display input integer on screen by printf()*/

	printf("Input a float, followed by <ENTER> key: ");		/* prompt message by printf() */
	scanf("%f",&fnum);										/* input a float by scanf()*/
	printf("Character <%f> is entered!\n",fnum);			/* display input float on screen by printf()*/

	return 0;
}
