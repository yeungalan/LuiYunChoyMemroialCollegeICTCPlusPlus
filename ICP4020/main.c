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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void ErrorHandler(char[],int);
void DocumentReader(char[255],struct Item dataArray[50],int *currentExistsRecordsNumber);
void DocumentWriter(char[255],struct Item dataArray[50]);
int chardatatypeschecking(char[]);

int main(int argc, char *argv[]) {
	fflush(stdin);
	int input;
	do{
		system("CLS"); // clean screen
		//print the UI
		printf("\n			***	Welcome to HKUSPACE Inventory Managment and Record System	***\n");
		printf("\n							***  1819S1  ***\n");
		printf("\n			***	This system is developed by CCIT4020 Class No. CL-06 Group No.4 ***\n");
		printf("\n\n");
		printf("--(Basic functions)--\n");
		printf("\n1. Add New Item(s):\n");
		printf("\n2. Display Item Record(s):\n");
		printf("\n3. Search Item Information:\n");
		printf("\n4. Modify Item Record(s)\n");
		printf("\n5. Delete Item Record(s):\n");
		printf("\n--(Extra functions)--\n");
		printf("\n6. Export to .csv:\n");
		printf("\n7. Sorting database:\n");
		printf("\n8. Date of editing record:\n");
		printf("\nWhat is your option (1-8)?");
		scanf("%d",&input);
		//redirct user to sutiable function
		switch(input){
			case 1:
				AddNewItems();
				break;
			case 2:
				display();
				break;
			case 3:
				search();
				break;
			case 4:
				modify();
				break;
			case 5:
				Delete();
				break;
			case 6:
				exportcsv();
				break;
			case 7:
				sort();
				break;
			case 8:
				DateofEditingRecord();
				break;
			default:
				// if error
				printf("Invaild Input.\n");
				system("PAUSE");
				break;
		}
	}while(input < 1 || input > 8); // if error then input again
	return 0;
}

//generic function , use for write the "database" stock.txt, accept args : (filename arg0 (string),item arg1 (struct Item))
void DocumentWriter(char filename[255],struct Item dataArray[50]){
	int i;
	FILE *outFILE;
	outFILE = fopen(filename,"w");
	for(i=0;i<50;i++){
		if(dataArray[i].recordnumber != '\0'){
			fprintf(outFILE,"%d\n",dataArray[i].recordnumber);
			fprintf(outFILE,"%s\n",dataArray[i].name);
			fprintf(outFILE,"%d\n",dataArray[i].itemnumber);
			fprintf(outFILE,"%s\n",dataArray[i].category);
			fprintf(outFILE,"%d\n",dataArray[i].quantity);
			fprintf(outFILE,"%.1f kg\n",dataArray[i].weight);
			fprintf(outFILE,"%s\n",dataArray[i].recipient);
			fprintf(outFILE,"%s\n",dataArray[i].finaldestination);
			fprintf(outFILE,"%s\n\n",dataArray[i].deliverystatus);
		}
		
	}
	
	fclose(outFILE);
}

//generic function , use for read the "database" stock.txt, accept args : (filename arg0 (string),item arg1 (struct Item),number of items arg2 (int))
void DocumentReader(char filename[255],struct Item dataArray[50],int *currentExistsRecordsNumber){
	int arrayCOUNTER = 0,characterCOUNTER = 0,characterPOSITION = 0;
	FILE *inFILE;
	inFILE = fopen(filename,"r");
	char ch,tmp[512];
	while((ch = fgetc(inFILE)) != EOF){
		if(ch == '\n'){
			switch(characterCOUNTER){
				case 0:
					dataArray[arrayCOUNTER].recordnumber = atoi(tmp);
					break;
				case 1:
					strcpy(dataArray[arrayCOUNTER].name,tmp);
					break;
				case 2:
					dataArray[arrayCOUNTER].itemnumber = atoi(tmp);
					break;
				case 3:
					strcpy(dataArray[arrayCOUNTER].category,tmp);
					break;
				case 4:
					dataArray[arrayCOUNTER].quantity = atoi(tmp);
					break;
				case 5:
					dataArray[arrayCOUNTER].weight = atof(tmp);
					break;
				case 6:
					strcpy(dataArray[arrayCOUNTER].recipient,tmp);
					break;
				case 7:
					strcpy(dataArray[arrayCOUNTER].finaldestination,tmp);
					break;
				case 8:
					strcpy(dataArray[arrayCOUNTER].deliverystatus,tmp);
					break;	
			}
			if(characterCOUNTER == 8){
				arrayCOUNTER += 1;
				characterCOUNTER = -1;
			}else{
				characterCOUNTER += 1;
			}
			characterPOSITION = 0;
			memset(tmp, 0, sizeof(tmp));
			
		}else{
			tmp[characterPOSITION] = ch;
			characterPOSITION += 1;
		}
		
	}
	fclose(inFILE);

	*currentExistsRecordsNumber = arrayCOUNTER;
}

//generic function , use for handle error (message arg0 (string), qut 0 for not quit, 1 for quit arg1 (int))
void ErrorHandler(char message[512],int qut){
	system("color 4F"); // chaneg colour
	system("CLS"); // clean screen
	printf("============================================\n");
	printf("ERROR!!! Encountered error during execution.\n");
	printf("Description :%s\n",message);
	if(qut == 1){
		printf("PROGRAM TERMINATED. Press anykey to exit.\n",message);
	}else{
		printf("Press anykey to return.\n",message);
	}
	printf("============================================\n");
	system("@PAUSE"); // show pause text
	system("color 07"); // restore color
	system("CLS");	 // clean again
	if(qut == 1){
		exit(1);
	}
}
