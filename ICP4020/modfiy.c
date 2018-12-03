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

void modify()
{
	char buffer[40];//init var
	fflush(stdin); //clean stdin
	system("CLS"); //clean screen
	struct Item Arr_Item[50] = {{0}}; //init var
	int currentExistsRecordsNumber;//init var
	DocumentReader("stock.txt",Arr_Item,&currentExistsRecordsNumber); // init data

	int i, a, b, ynflag; //init var
	char yn;//init var
	printf(" CCIT4020-ICP-GroupProject\n"); //print std header and ask for input
	printf("\n HKUSPACE Inventory Management and Record System\n Powered by Lai Wing Chung (20089713)\n Modify Item Record(s):\n");
	printf("\n\n\n");
	printf("Press 1 to update the existing item\n");
	printf("Press 0 to go back to menu page\n");
	printf("Input the required number: ");
	scanf("%d", &a);
	printf("\n");
	if(a==1)
	{
		//ask user want update which record
	printf("Please enter the record number you want to update: ");
	scanf("%d", &i);
	printf("\n");
	int existchecker = 0,exists = 0;
	for(existchecker=0;existchecker<currentExistsRecordsNumber;existchecker++) { 
		if(i==Arr_Item[existchecker].recordnumber){
			//check if that user exits
			exists = 1; 
			break;
		}
	} 
	if(exists == 1){
		//if exists then print which item user want edit
		printf("1:Item name 			 2:Item number \n");
		printf("3:Category			 4:Quantity \n");
		printf("5:Weight			 6:Recipient\n");
		printf("7:Final Destination		 8:Delivery status\n");
		printf("Select the required information to update: ");
		scanf("%d", &b);
		if(b > 8 || b < 1){
			// check if invaild
			printf("Wrong input number.\n");
		}else{
			//ask for update
			printf("Please enter the updated information: ");
			fflush(stdin);
			gets(buffer);
			//base on user selection update speftic row		
		    switch (b){
		    	case 1:
		    		strcpy(Arr_Item[existchecker].name,buffer);
					break;
			    case 2:
					Arr_Item[existchecker].itemnumber = atoi(buffer);
					break;
			    case 3:
					strcpy(Arr_Item[existchecker].category,buffer);
					break;
			    case 4:
					Arr_Item[existchecker].quantity = atoi(buffer);
					break;
			    case 5:
					Arr_Item[existchecker].weight = atof(buffer);
					break;
			    case 6:
					strcpy(Arr_Item[existchecker].recipient,buffer);
					break;
			    case 7:
					strcpy(Arr_Item[existchecker].finaldestination,buffer);
					break;
			    case 8:
			    	strcpy(Arr_Item[existchecker].deliverystatus,buffer);
					break;
				}
				
				//clean stdin and tell user complete
			fflush(stdin);
			printf("Record: %d has been updated to %s.\n",Arr_Item[existchecker].recordnumber,buffer);
			DocumentWriter("stock.txt",Arr_Item);
		}
		}else{
			printf("Record NOT EXISTS. \n");
		}
	}
	system("PAUSE");
	main();
}
