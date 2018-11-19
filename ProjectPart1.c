#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Item{
	int recordnumber;
	char name;
	int itemnumber;
	char category;
	int quantity;
	float weight;
	char recipient;
	char finaldestination;
	char deliverystatus;
};

int chardatatypeschecking(int,int,char[]);

int main(){
	struct Item Arr_Item[50];
	char inputmessage[255];
	int lasti = 0 ,lastflag = 0,currentStringPart = 0,i;
	int IntCase = 0, FloatCase = 0, CharCase = 0;
	
	printf("Please enter 1) Record number, 2) Item name, 3) Item number, 40 Category, 5) Quantity 6) Weight 7) Recipient 8) Final Destination, and 9) Delivery status:");
	gets(inputmessage);
	while(inputmessage[i] != '\0'){
		if(isspace(inputmessage[i]) || strlen(inputmessage) == i +1){
			int flag = chardatatypeschecking(lasti,i,inputmessage);
			switch(flag){
				case 1:
					if(currentStringPart == 0){
						int StringLocation;
						for(StringLocation=lasti;StringLocation <= i;StringLocation++){
							Arr_Item[0].recordnumber = atoi(inputmessage[StringLocation]);
						}
					}
					break;
				case 2:
					break;	
				case 3:
					break;
			};
		lastflag = flag;		
		lasti = i;
		currentStringPart = currentStringPart + 1;
	}
	i = i + 1;
	}
	
	printf("%d %s %d %s %d %f",Arr_Item[0].recordnumber,Arr_Item[0].name,Arr_Item[0].itemnumber,Arr_Item[0].category,Arr_Item[0].quantity,Arr_Item[0].weight);
}

int chardatatypeschecking(int firsti,int lasti,char chararray[]){
	int i = 0,AlphaCounter = 0,DigitCounter = 0,DotCounter = 0,SpaceCounter = 0;
	for(i=firsti;i<=lasti;i++){
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
		//printf("%c / S%d / D%d / A%d / Digit%d\n",chararray[i],SpaceCounter,DotCounter,AlphaCounter,DigitCounter);
	}
	
	if(DigitCounter == (lasti - firsti + 1) - SpaceCounter){
		return 1; //int
	}else if(DotCounter == 1 && DigitCounter == (lasti - firsti + 1) - 1 - SpaceCounter){
		return 2; //float
	}else{
		return 3; //char
	}
};
