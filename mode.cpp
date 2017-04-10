#include <stdio.h>
#include <stdlib.h>
int chan[10];
int mtwo;
int i;
int main(){
	
for(i=0;i<10;i++){
	scanf("%d",&chan[i]);
//	chan[i] = i;
//	printf("%d \n",chan[i]);
}

//chan[1] = 2;

printf("stage i end \n");

//max
for(i=0;i<10;i++){
if(chan[i]>=mtwo){
	mtwo = chan[i];
}
}

//printf("max %d \n",mtwo);
//printf("stage ii end");

int chanho[mtwo+1];

//some suffers 
i=0;
for(i=0;i<10;i++){
chanho[chan[i]] =0;
}

for(i=0;i<10;i++){
chanho[chan[i]] = chanho[chan[i]] + 1;
//printf("%d \n",chan[i]);
//printf("%d \n",chanho[chan[i]]);
}

mtwo =0;
int mthree;
for(i=0;i<10;i++){
if(chanho[chan[i]]>=mtwo){
	mtwo = chanho[chan[i]];
	mthree = chan[i];
}
}

printf(" Result : %d , duplicate %d times",mthree , mtwo);
system("color 0A");
return 0;
}

