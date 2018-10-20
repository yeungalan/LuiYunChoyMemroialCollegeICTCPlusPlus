#include <stdio.h>
int main(){
	float mark;
	char grade;
	printf("Enter the student's numerical grade: ");
	scanf("%f",&mark);
	if(mark >= 90.0){
		grade = 'A';
	}else if(mark >= 80.0){
		grade = 'B';
	}else if(mark >= 70.0){
		grade = 'C';
	}else if(mark >= 60.0){
		grade = 'D';
	}else if(mark >= 50.0){
		grade = 'E';
	}else if(mark > 0.0){
		grade = 'F';
	}else{
		grade = 'G';
	}
	printf("The student recives a grade of %c",grade);
	return 0;
}
