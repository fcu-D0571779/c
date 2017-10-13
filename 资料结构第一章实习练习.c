#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void Hanoi(char n, char frompg,char topg, char auxpg){
	if(n == 1) {
		printf("Move disk %d from %c to %c\n",n,frompg,topg);
		return;
	}
	Hanoi(n - 1, frompg, auxpg, topg);
	printf("Move disk %d from %c to %c\n", n, frompg, topg);
	Hanoi(n - 1, auxpg, topg, frompg);
}

void PERM(char list[], int start, int end){
	int i, temp;
	if(start == end){
		printf("{%c,%c,%c,%c,%c}\n",list[0],list[1],list[2],list[3],list[4]);
	}
	else{
		for(i = start; i < end; i++){
			SWAP(list[start], list[i], temp);
			PERM(list, i, end);
			SWAP(list[i], list[start], temp);
		}
	}
}

//MAGIC_SQUARE
void MAGIC_SQUARE(int n, int array[15][15]){
	int row = 0, col = n / 2, i, j,temp1, temp2;
	array[row][col] = 1;
	for(i = 1; i < n * n; i++){
		temp1 = row;
		temp2 = col;
		row--;
		col--;
		if(row < 0) row += n;
		if(col < 0) col += n;
		if(array[row][col] == 0) array[row][col] = i + 1;
		else{
			row = temp1 + 1;
			col = temp2;
			array[row][col] = i + 1;
		}
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%5d ", array[i][j]);
		}
		printf("\n");
	}
}

int main(){
	//Hanoi
	int i, j,  number_n, n = 3;
	char kk[3] = {65, 66, 67};
	Hanoi(n, kk[0], kk[1], kk[2]);

/*
	//permutation
	char list = {"A", "B", "C", "D", "E"};
	int start = 0, end = 4, i;
	for(i = start; i < end; i++){
		PERM(list, start, end);
	}
*/


	//magic square
	int array[15][15];
	for(i = 0; i < 15; i++){
		for(j = 0; j < 15; j++){
			array[i][j] = 0;
		}
	}
	scanf("%d", &number_n);
	MAGIC_SQUARE(number_n, array);

	return 0;
}
