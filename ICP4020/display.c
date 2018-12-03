#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//  this is a struct for storing the core information
struct Item{
	int recordnumber;
	char name[40];
	int itemnumber;
	char category[40];
	int quantity;
	float weight;
	char recipient[40];
	char finaldestination[40];
	char deliverystatus[40];
};

void ErrorHandler(char[],int);
void DocumentReader(char[255],struct Item dataArray[50],int *currentExistsRecordsNumber);
void DocumentWriter(char[255],struct Item dataArray[50]);
int chardatatypeschecking(char[]);

int display(){
	fflush(stdin);
	system("CLS"); // clean input
	struct Item Arr_Item[50] = {{0}}; //init a empty array
	int currentExistsRecordsNumber; // init var
	DocumentReader("stock.txt",Arr_Item,&currentExistsRecordsNumber); //init data
	
	//std header
	printf(" CCIT4020-ICP-GroupProject\n");
	printf("\n HKUSPACE Inventory Management and Record System\n Powered by Cheng Hoi Ming (20089483)\n Display Item Record(s):\n");
	printf("\n\n\n");
	
	int i=0;
	for(i=0; i<currentExistsRecordsNumber; i++)
	{
		// print result
		printf("Record %d out of %d\n",i+1,currentExistsRecordsNumber);
		printf("Record number: 		%d\n", Arr_Item[i].recordnumber);
		printf("Name: 			%s\n", Arr_Item[i].name);
		printf("Item number: 		%d\n", Arr_Item[i].itemnumber);
		printf("Category: 		%s\n", Arr_Item[i].category);
		printf("Quantity: 		%d\n", Arr_Item[i].quantity);
		printf("Weight: 		%.1f kg\n", Arr_Item[i].weight);
		printf("Recipient: 		%s\n", Arr_Item[i].recipient);
		printf("Final destination: 	%s\n", Arr_Item[i].finaldestination);
        printf("Delivery Status: 	%s\n", Arr_Item[i].deliverystatus);
        printf("-----------\n\n");

	}
	system("PAUSE"); //pause for wait user read to end
	main();	
}



