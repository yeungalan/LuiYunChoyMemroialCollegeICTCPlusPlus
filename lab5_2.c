#include <stdio.h>
int main(){
	int num;
	int pass = 88;
	do{
		fflush(stdin);																				/* flush the stdin cache */
		printf("Guess what the lucky number is (between 1 and 100), then <Enter>:");				/* print string */
		scanf("%d",&num);																			/* ask user to input string */
		if(num < pass && num >= 1){ 															    /* if num is bigger than 1 and less than lucky number */
			printf("The number you typed is [%d] Too small, guess the lucky number again!\n",num); /* print string */
		}else if(num > pass && num <= 100){														   /* if num is bigger than 1 and less than lucky number */
			printf("The number you typed is [%d] Too LARGE, guess the lucky number again!\n",num); /* print string */
		}else if(num == pass){																	   /* if num = lucky number */
			printf("OK! This is your LUCKY NUMBER [%d]. Well Done!... QUIT!\n",num);			   /* print string */
			break;																				   /* break the loop*/
		}else{																					   /* out of range */
			printf("The input number [%d] is OUT of range... QUIT!\n",num);						   /* print string */
			break;																				   /* break the loop*/
		}
		
	}while (num >= 1 && num <= 100 && num != pass);

	
	return 0;
}
