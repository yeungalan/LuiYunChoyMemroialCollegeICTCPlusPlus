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

int AddNewItems(){
	fflush(stdin);
	int exit_flag = 0;
	//ErrorHandler("THIS IS EXAMPLE EXCEPTION",1);
	do{
		system("CLS"); // clean screen
		struct Item Arr_Item[50] = {{0}}; // create a array with empty values inside
		int currentExistsRecordsNumber; // current items number , will store value after documentreader()
		DocumentReader("stock.txt",Arr_Item,&currentExistsRecordsNumber); // read files
			
		int TempCharArrayCounterForLastThreeItems = 0; //declare variable
		int flag = 1,counter[5],IsContinueCharInput = 0; //declare variable
		counter[1] = 0;//declare variable
		counter[2] = 0;//declare variable
		counter[3] = 0;//declare variable
		
		//print standard header and asking user
		printf(" CCIT4020-ICP-GroupProject\n");
		printf("\n HKUSPACE Inventory Management and Record System\n Powered by Yeung Ho Lun(20093247)\n Add new item(s):\n");
		printf("\n\n\n");	
		printf("Please enter 1) Record number, 2) Item name, 3) Item number, 4) Category, 5) Quantity 6) Weight 7) Recipient 8) Final Destination, and 9) Delivery status:\n");
		while(flag){ //while all input was processed
			char tmp[20]; // declare var
			scanf("%s",tmp); // ask for input
		
			// switch for checking the part of data is belongs to which part , uses for sort data into suitable palce
			switch(chardatatypeschecking(tmp)){
				case 1:
					if(counter[1] == 0){
						Arr_Item[currentExistsRecordsNumber].recordnumber = atoi(tmp); //storing
					}else if(counter[1] == 1){
						Arr_Item[currentExistsRecordsNumber].itemnumber = atoi(tmp);	//storing
					}else if(counter[1] == 2){
						Arr_Item[currentExistsRecordsNumber].quantity = atoi(tmp);	//storing
					}
					counter[1] += 1;
					IsContinueCharInput = 0;
					break;
				case 2:
					if(counter[2] == 0){
						Arr_Item[currentExistsRecordsNumber].weight = atof(tmp);//storing
					}
					counter[2] += 1;
					IsContinueCharInput = 0;
					break;
				case 3:
					if(IsContinueCharInput == 0){
						counter[3] += 1;
					}
					strcat(tmp," ");
					if(counter[3] == 1){
						strcat(Arr_Item[currentExistsRecordsNumber].name,tmp);//storing
					}else if(counter[3] == 2){
						strcat(Arr_Item[currentExistsRecordsNumber].category,tmp);//storing
					}else if(counter[3] == 3){
						if(TempCharArrayCounterForLastThreeItems == 2){
							counter[3] += 1;
							TempCharArrayCounterForLastThreeItems = 0; // this counter use for count is string inputed 2 part or 3 part , uses on last 3 input split them into different part
						}
						//printf("%d %s\n",TempCharArrayCounterForLastThreeItems,tmp);
						strcat(Arr_Item[currentExistsRecordsNumber].recipient,tmp);//storing
						TempCharArrayCounterForLastThreeItems += 1; // this counter use for count is string inputed 2 part or 3 part , uses on last 3 input split them into different part
					}else if(counter[3] == 4){
						if(TempCharArrayCounterForLastThreeItems == 2){
							counter[3] += 1;
							TempCharArrayCounterForLastThreeItems = 0; // this counter use for count is string inputed 2 part or 3 part , uses on last 3 input split them into different part
						}
						//printf("%d %s\n",TempCharArrayCounterForLastThreeItems,tmp);
						strcat(Arr_Item[currentExistsRecordsNumber].finaldestination,tmp);//storing
						TempCharArrayCounterForLastThreeItems += 1; // this counter use for count is string inputed 2 part or 3 part , uses on last 3 input split them into different part
					}else if(counter[3] == 5){
						strcat(Arr_Item[currentExistsRecordsNumber].deliverystatus,tmp);//storing
						flag = 0;
					}
					//printf("%d %s\n",counter[3],tmp);
					IsContinueCharInput = 1;
					break;
			}
		};
		//print results
		printf(" \n \nThe input has been recognized by system, please check the input data integrity at here: \n");
		printf("Record number :		%d \n",Arr_Item[currentExistsRecordsNumber].recordnumber);
		printf("Name : 			%s \n",Arr_Item[currentExistsRecordsNumber].name);
		printf("Item Number :		%d \n",Arr_Item[currentExistsRecordsNumber].itemnumber);
		printf("Category : 		%s \n",Arr_Item[currentExistsRecordsNumber].category);
		printf("Quantity : 		%d \n",Arr_Item[currentExistsRecordsNumber].quantity);
		printf("Weight : 		%f \n",Arr_Item[currentExistsRecordsNumber].weight);
		printf("Recipient : 		%s \n",Arr_Item[currentExistsRecordsNumber].recipient);
		printf("Final destination : 	%s \n",Arr_Item[currentExistsRecordsNumber].finaldestination);
		printf("Delivery status : 	%s \n",Arr_Item[currentExistsRecordsNumber].deliverystatus);
		
		//ask for input correct or not
		int checkifcorrect = 0;
		printf("Did you want to write those data into database? (1 for Yes , 0 for No)");
		scanf("%d",&checkifcorrect);
		if(checkifcorrect == 1){
			printf("Operation completed.\n");
			DocumentWriter("stock.txt",Arr_Item);
		}else{
			printf("Operation cancelled.\n");
		}
		
		//ask for want one more record ?
		printf("Wants to add one more record? (1 for Yes , 0 for No)");
		scanf("%d",&exit_flag);
	}while(exit_flag == 1);
	main();
}

//use for check the character is belongs to float or int or string , return 1 = int , 2 = float , 3 = char
int chardatatypeschecking(char chararray[]){
	int i = 0,AlphaCounter = 0,DigitCounter = 0,DotCounter = 0,SpaceCounter = 0;
	for(i=0;i<=strlen(chararray);i++){
		if(!isspace(chararray[i])){
			if(isalpha(chararray[i])){
				AlphaCounter = AlphaCounter + 1;
			}else if(isdigit(chararray[i])){
				DigitCounter = DigitCounter + 1 ;
			}else if(chararray[i] == '.'){
					DotCounter = DotCounter + 1;
			}
			
		}else{
			SpaceCounter = SpaceCounter + 1;
		}
	}
	//printf("%s / S%d / D%d / A%d / Digit%d\n",chararray,SpaceCounter,DotCounter,AlphaCounter,DigitCounter);
	if(DigitCounter == strlen(chararray)){
		return 1; //int
	}else if(DotCounter == 1 && DigitCounter == strlen(chararray) - 1){
		return 2; //float
	}else{
		return 3; //char
	}
};

