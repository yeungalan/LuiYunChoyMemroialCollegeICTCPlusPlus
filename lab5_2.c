#include <stdio.h>
int main(){
	int num;
	int pass = 88;
	do{
		fflush(stdin);
		printf("Guess what the lucky number is (between 1 and 100), then <Enter>:");
		scanf("%d",&num);
		if(num < pass && num >= 1){
			printf("The number you typed is [%d] Too small, guess the lucky number again!\n",num);
		}else if(num > pass && num <= 100){
			printf("The number you typed is [%d] Too LARGE, guess the lucky number again!\n",num);
		}else if(num == pass){
			printf("OK! This is your LUCKY NUMBER [%d]. Well Done!... QUIT!\n",pass);
		}
		
	}while (num >= 1 && num <= 100 && num != pass);
	if(num != pass){
		printf("The input number [%d] is OUT of range... QUIT!\n",num);
	}
	
	return 0;
}
