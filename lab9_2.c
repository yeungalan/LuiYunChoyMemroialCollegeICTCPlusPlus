#include <stdio.h>

int main(){
	FILE *outFILE,*inFILE;
	char name[20],outName[20];
	int i,math,comp,outMath,outComp;
	
	outFILE = fopen("school.txt","w");
	
	printf("Enter names & two subjects marks (Mathematics and Computing) of five students: \n");
	for(i=0;i<5;i++){
		scanf("%s %d %d",&name,&math,&comp);
		fprintf(outFILE,"%s %d %d",name,math,comp);
	}
	fclose(outFILE);
	printf("OUTPUT file writing finished OK! \n");
	
	inFILE = fopen("school.txt","r");
	printf("\nData in file is:\n\n");
	printf("Name    Mathematics     Computing\n");
	printf("----    -----------     ---------\n");
	while(fscanf(inFILE,"%s %d %d",outName,&outMath,&outComp)	!= EOF){
		printf("%-7s %-15d %d\n",outName,outMath,outComp);
	}
	fclose(outFILE);
	
	return 0;
	
}
