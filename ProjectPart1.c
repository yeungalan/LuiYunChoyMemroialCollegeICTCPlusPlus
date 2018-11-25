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
void DocumentWriter(char[255],struct Item dataArray[50]);
int chardatatypeschecking(char[]);

int main(){
	struct Item Arr_Item[50] = {{0}};
	int currentExistsRecordsNumber;
	DocumentReader("stock.txt",Arr_Item,&currentExistsRecordsNumber);
	
	printf("%d",currentExistsRecordsNumber);
	
	int TempCharArrayCounterForLastThreeItems = 0;
	int flag = 1,counter[5],IsContinueCharInput = 0;
	counter[1] = 0;
	counter[2] = 0;
	counter[3] = 0;
	
	printf("¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i CCIT4020-ICP-GroupProject ¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i\n");
	printf("\n HKUSPACE Inventory Management and Record System\n Powered by Yeung Ho Lun(20093247)\n Add new item(s):\n");
	printf("\n\n\n");	
	printf("Please enter 1) Record number, 2) Item name, 3) Item number, 4) Category, 5) Quantity 6) Weight 7) Recipient 8) Final Destination, and 9) Delivery status:\n");
	while(flag){
		char tmp[20];
		scanf("%s",tmp);
	
		switch(chardatatypeschecking(tmp)){
			case 1:
				if(counter[1] == 0){
					Arr_Item[currentExistsRecordsNumber].recordnumber = atoi(tmp);
				}else if(counter[1] == 1){
					Arr_Item[currentExistsRecordsNumber].itemnumber = atoi(tmp);	
				}else if(counter[1] == 2){
					Arr_Item[currentExistsRecordsNumber].quantity = atoi(tmp);	
				}
				counter[1] += 1;
				IsContinueCharInput = 0;
				break;
			case 2:
				if(counter[2] == 0){
					Arr_Item[currentExistsRecordsNumber].weight = atof(tmp);
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
					strcat(Arr_Item[currentExistsRecordsNumber].name,tmp);
				}else if(counter[3] == 2){
					strcat(Arr_Item[currentExistsRecordsNumber].category,tmp);
				}else if(counter[3] == 3){
					if(TempCharArrayCounterForLastThreeItems == 2){
						counter[3] += 1;
						TempCharArrayCounterForLastThreeItems = 0;
					}
					//printf("%d %s\n",TempCharArrayCounterForLastThreeItems,tmp);
					strcat(Arr_Item[currentExistsRecordsNumber].recipient,tmp);
					TempCharArrayCounterForLastThreeItems += 1;
				}else if(counter[3] == 4){
					if(TempCharArrayCounterForLastThreeItems == 2){
						counter[3] += 1;
						TempCharArrayCounterForLastThreeItems = 0;
					}
					//printf("%d %s\n",TempCharArrayCounterForLastThreeItems,tmp);
					strcat(Arr_Item[currentExistsRecordsNumber].finaldestination,tmp);
					TempCharArrayCounterForLastThreeItems += 1;
				}else if(counter[3] == 5){
					strcat(Arr_Item[currentExistsRecordsNumber].deliverystatus,tmp);
					flag = 0;
				}
				//printf("%d %s\n",counter[3],tmp);
				IsContinueCharInput = 1;
				break;
		}
	};

	/* yea this is the fucking debug unit, do not remove this fucking part */
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
	system("PAUSE");
	DocumentWriter("stock.txt",Arr_Item);
}


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

