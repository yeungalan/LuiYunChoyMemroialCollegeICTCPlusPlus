#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void DocumentReader(char[255],struct Item dataArray[50],int *currentExistsRecordsNumber);
	
void search()  
{
	system("CLS");
	struct Item Arr_Item[50] = {{0}};
	int currentExistsRecordsNumber;
	DocumentReader("stock.txt",Arr_Item,&currentExistsRecordsNumber);

	int i,a,b; 
	char c; 
	char _name[40]; 
	FILE *fp1;
		
	fp1=fopen("stock.txt","r+");

	while(1) 
	{ 
		system("CLS");
		printf(" CCIT4020-ICP-GroupProject\n");
		printf("\n HKUSPACE Inventory Management and Record System\n Powered by Ho Chun Pong (20057174)\n Search Item Information:\n");
		printf("\n\n\n");
		printf("1 - Search by record number \n"); 
		printf("2 - Search by item name \n"); 
		printf("0 - Back to menu page \n"); 
		printf("Please input your selection (0-2): ",a); 
		scanf("%d",&a); 
		if(a==1) 
		{ 
			fflush(stdin);
			printf("Please Enter the record number: "); 
			scanf("%d",&b); 
			printf("\n"); 
			for(i=0;i<currentExistsRecordsNumber;i++) 
			{ 
				if(b==Arr_Item[i].recordnumber) break; 
			} 
			if(i<Arr_Item[i].itemnumber){ 
				printf("Record quered as follows:\n");
				printf("Record number: 		%d\n", Arr_Item[i].recordnumber);
				printf("Name: 			%s\n", Arr_Item[i].name);
				printf("Item number: 		%d\n", Arr_Item[i].itemnumber);
				printf("Category: 		%s\n", Arr_Item[i].category);
				printf("Quantity: 		%d\n", Arr_Item[i].quantity);
				printf("Weight: 		%.1f kg\n", Arr_Item[i].weight);
				printf("Recipient: 		%s\n", Arr_Item[i].recipient);
				printf("Final destination: 	%s\n", Arr_Item[i].finaldestination);
    		    printf("Delivery Status: 	%s\n", Arr_Item[i].deliverystatus);
			}else{ 
				printf("Not found.\n"); 
			}
			printf("Start a new query? (Y/N): "); 
			scanf(" %c",&c); 
			if(c=='N'||c=='n') break; 
		} 
		else if(a==2) 
		{ 
			fflush(stdin);
			printf("Please Enter the item name: "); 
			gets(_name);
			strcat(_name," "); 
			printf("\n"); 
			for(i=0;i<currentExistsRecordsNumber;i++) 
			{ 
				if(strcmp(_name,Arr_Item[i].name)==0) break; 
			} 
			if(i<currentExistsRecordsNumber){ 
				printf("Record quered as follows:\n");
				printf("Record number: 		%d\n", Arr_Item[i].recordnumber);
				printf("Name: 			%s\n", Arr_Item[i].name);
				printf("Item number: 		%d\n", Arr_Item[i].itemnumber);
				printf("Category: 		%s\n", Arr_Item[i].category);
				printf("Quantity: 		%d\n", Arr_Item[i].quantity);
				printf("Weight: 		%.1f kg\n", Arr_Item[i].weight);
				printf("Recipient: 		%s\n", Arr_Item[i].recipient);
				printf("Final destination: 	%s\n", Arr_Item[i].finaldestination);
    		    printf("Delivery Status: 	%s\n", Arr_Item[i].deliverystatus);
			}else{
				printf("Not found.\n"); 
			}
			printf("Start a new query? (Y/N): "); 
			scanf(" %c",&c); 
			if(c=='N'||c=='n') break; 
		} 
		else if(a==0) break;
	}
	fclose(fp1);
	main();
}
