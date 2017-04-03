#include <stdio.h>
#include <stdlib.h>

int chanho[90];
int cannotstudy[90];

int i=0;
int ii=0;
int main(){
	
for(i=0;i<=10;i++){
	scanf("%d",&chanho[i]);
}

i=0;
while(i!=11){ 
cannotstudy[11-i] = chanho[i];
 i=i+1;
}

printf("==== \n");
for(i=0;i<12;i++){
	if(cannotstudy[i]==0){
	}else{
		printf("%d \n",cannotstudy[i]);
	}	
}

return 0;
}

