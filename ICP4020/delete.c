#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void Delete()
{	
	fflush(stdin);
	system("CLS"); // clean screen
	FILE *ft=fopen("temp.txt","w"); // open file
	FILE *fp=fopen("stock.txt","r");
	int temp=0; // declare
	int re;
	char a[1000];
	char b[1000];
	char c[5]="\n";
	do
	{
	system("CLS"); //print standard header and ask for input
	printf(" CCIT4020-ICP-GroupProject\n");
	printf("\n HKUSPACE Inventory Management and Record System\n Powered by Wong Ho Tang (20079455)\n Delete Item Record(s):\n");
	printf("\n\n\n");
	printf("Enter Record number to delete:");
	scanf("%s",b);
	printf("\n");
	strcat(b,"\n");
	if(ft==NULL || fp==NULL){ //check if null
		printf("ERROR\n");
		exit(0);
	}
	
	while(fgets(a,1000,fp))
	    {
	    	if(strcmp(a,b)!=0 && temp==0)
	    	    {
	    	    	//printf("%s",a);
	    	    	fputs(a,ft);
				}
				else
				{
					temp = 1;
					if(strcmp(a,c)==0)
					temp = 0;
				}
		}
	fclose(ft);
	fclose(fp);
	remove("stock.txt");
	rename("temp.txt","stock.txt");
	printf("Deleting record number %s Successful.\n",b); // finishing function
	printf("Do you want to Delete another item record?(1/0)");
	scanf("%d",&re);
	}while(re==1);
	main();
}
