/*
Name:KEITH BARRACK OJUANG
Reg no:PA106/G/29044/25
Description:A program to display the elements in an array
*/

#include<stdio.h>

int main(){
	
	int scores[4][2] = {
	    {65, 92},
		{84, 72},
		{35, 70},
		{59, 69}
			
	};
	int i, j;
	
	printf("Elements of the array are:\n");
	  for (i = 0; i < 4; i++){
		for (j = 0; j < 2; j++){
			
		printf("%d\t",scores[i][j]);
	}
	printf("\n");
	}
	
	return 0;
	
}