#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

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

int exportcsv(){
	fflush(stdin);
	system("CLS");
	struct Item Arr_Item[50] = {{0}};
	int currentExistsRecordsNumber;
	DocumentReader("stock.txt",Arr_Item,&currentExistsRecordsNumber);

	FILE *outCSV;
	int i=0;
	float mean_weight = 0.0 ,sd_weight = 0.0 ,sum_weight = 0.0;
	float mean_quantity = 0.0 ,sd_quantity = 0.0 ,sum_quantity = 0.0;
	char filename[255];
	system("CLS");
	printf(" CCIT4020-ICP-GroupProject\n");
	printf("\n HKUSPACE Inventory Management and Record System\n Powered by Yeung Ho Lun (20093247)\n Export to .csv:\n");
	printf("\n\n\n");
	printf("Additional PART: Export to Excel compatible file format:\nPlease enter filename (include .csv):");
	gets(filename);
	outCSV = fopen(filename,"w");
	fputs("Record Number,Name,Item Number,Category,Quantity,Weight,Recipient,Final Destination,Delivery Status\n",outCSV);
	for(i=0;i<currentExistsRecordsNumber;i++){
		fprintf(outCSV,"%d,%s,%d,%s,%d,%f,%s,%s,%s\n",Arr_Item[i].recordnumber,Arr_Item[i].name,Arr_Item[i].itemnumber,Arr_Item[i].category,Arr_Item[i].quantity,Arr_Item[i].weight,Arr_Item[i].recipient,Arr_Item[i].finaldestination,Arr_Item[i].deliverystatus);	
		sum_weight += Arr_Item[i].weight;
		sum_quantity += Arr_Item[i].quantity;
	}
	
	mean_quantity = sum_quantity / currentExistsRecordsNumber;
	mean_weight = sum_weight / currentExistsRecordsNumber;	
	for(i=0;i<currentExistsRecordsNumber;i++){
		sd_quantity += pow(Arr_Item[i].quantity - mean_quantity, 2);
		sd_weight += pow(Arr_Item[i].weight - mean_weight, 2);
	}
	sd_quantity = sqrt(sd_quantity/currentExistsRecordsNumber);
	sd_weight = sqrt(sd_weight/currentExistsRecordsNumber);
	
	fputs("\nStatistics,Quantity,Weight\n",outCSV);
	fprintf(outCSV,"STD,%f,%f\n",sd_quantity,sd_weight);
	fprintf(outCSV,"MEAN,%f,%f\n",mean_quantity,mean_weight);
	fclose(outCSV);
	
	printf("Export to %s complete.\n",filename);
	system("PAUSE");
	main();
}



