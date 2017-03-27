#include <stdio.h>
#include <stdlib.h>
int main(){
	int chanho[10];
	int i=0;
	int a=0;
	int indess=0;
	for(i=0;i<10;i++){
		scanf("%d",&chanho[i]);
	}
	for(i=0;i<10;i++){
		if(a>=chanho[i+1]){
			printf("%d >= %d Not doing\n",a,chanho[i+1]);
		}else{
			a = chanho[i+1];
			indess = i + 1;
			printf("%d < %d doing\n",a,chanho[i+1]);
		}		
	}
	printf("%d , Index : %d",a,indess);
	system("PAUSE");
	printf("Hey man do you want to play again ? if yes please enter 1!!!!");
	int moduletwo;
	scanf("%d",&moduletwo);
	if (moduletwo!=1){
	}else{
		system("start FindMaxValue.exe");
	}
	return 0;
} 
