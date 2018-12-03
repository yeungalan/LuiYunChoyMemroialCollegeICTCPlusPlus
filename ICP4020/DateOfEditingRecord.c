#include <stdio.h>
int DateofEditingRecord()
{
	int rc;
	do{
		fflush(stdin);
		int choose = 0;
		system("CLS");
		printf(" CCIT4020-ICP-GroupProject\n");
		printf("\n HKUSPACE Inventory Management and Record System\n Powered by Wong Ho Tang(20079455)\n Date of Editing Record:\n");
		printf("\n\n\n");
		printf("1 - Enter date entry\n");
		printf("2 - View date entry\n");
		printf("Please input for action: ");
		scanf("%d",&choose);
		
		if(choose == 1){
			int i;
			FILE *fptr;
			int recordnumber,year,month,day;
			fptr = fopen("date.txt", "a");
			
	   	    printf("Enter Record Number: ", i);
	   	    scanf("%d",&recordnumber);
	        printf("Enter Date in (Year Month Day): ", i);
	   	    scanf("%d %d %d",&year,&month,&day);
	   	    
	       	printf("The [Record Number] and the (Date) inputed are [%d]-(%d/%d/%d)\n", recordnumber,year,month,day);
	        fprintf(fptr,"%d %d %d %d", recordnumber,year,month,day);
	        fclose(fptr);
		}else if(choose == 2){
			int recordnumber,year,month,day;
			FILE *inFILE;
			inFILE = fopen("date.txt","r");
			if(inFILE == NULL){
				printf("NO Entry Created.\n");
			}else{
				while(fscanf(inFILE,"%d %d %d %d",&recordnumber,&year,&month,&day) != EOF){
					printf("[%d] Date of record created or modified: %d-%d-%d\n", recordnumber,year,month,day);
				}
			}
			fclose(inFILE);
		}else{
			printf("INVAILD INPUT\n");
			system("PAUSE");
		}

	printf("Do you want to countiue (1/0) ?");
	scanf("%d", &rc);
	}while (rc==1);
	return 0;
}
