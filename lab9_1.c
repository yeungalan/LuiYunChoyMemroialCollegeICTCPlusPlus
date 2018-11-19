#include <stdio.h>

int main(){
	FILE *outFILE,*inFILE;
	char filename[255],data[512];
	
	printf("Please enter OUTPUT file name for writing: ");
	gets(filename);
	outFILE = fopen(filename,"w");
	printf("Please enter a message (string) for writing:");
	gets(data);
	fputs(data,outFILE);
	fclose(outFILE);
	printf("OUTPUT file writing finished OK!\n");
	
	printf("\nPlease enter INPUT file name for writing: ");
	gets(filename);
	inFILE = fopen(filename,"w");
	fgets(data,255,inFILE);
	printf("Text data in the file <%s> are:\n",filename);
	puts(data);
	fclose(inFILE);
	
	return 0;
}
