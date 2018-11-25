#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int AddNewItems();

int main(int argc, char *argv[]) {
	int input;
	do{
		system("CLS");
		printf("\n			***	Welcome to HKUSPACE Inventory Managment and Record System	***\n");
		printf("\n							***  1819S1  ***\n");
		printf("\n			***	This system is developed by CCIT4020 Class No. ?L-?? Group No.?? ***\n");
		printf("\n\n");
		printf("--(Basic functions)--\n");
		printf("\n1. Add New Item(s):\n");
		printf("\n2. Display Item Record(s):\n");
		printf("\n3. Search Item Information:\n");
		printf("\n4. Modify Item Record(s)\n");
		printf("\n5. Delete Item Record(s):\n");
		printf("\n--(Extra functions)--\n");
		printf("\n6. Export to .csv:\n");
		printf("\nWhat is your option (1-6)?");
		scanf("%d",&input);
		switch(input){
			case 1:
				AddNewItems();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				printf("Invaild Input.\n");
				system("PAUSE");
				break;
		}
	}while(input < 1 || input > 6);
	return 0;
}
