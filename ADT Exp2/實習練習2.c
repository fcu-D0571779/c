#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MALLOC(p, s)\
    if(!((p) = malloc(s)))\
    {\
        fprintf(stderr, "Insufficient memory");\
        exit (EXIT_FAILURE);\
    }

int **make2darray(int rows, int cols){
    int **x, i;
    MALLOC(x,rows * sizeof(int));
    for(i = 0; i < rows; i++){
		MALLOC(x[i], cols * sizeof(**x));
	}
    return x;
}

int main(int argc, char const *argv[]) {
    int **ptr1, **ptr2;
    int i, j,temp, rows = 5, cols = 5;
    srand(time(NULL));
	//scanf("%d %d", &rows, &cols);

    ptr1 = make2darray(rows, cols);
    for(i = 0;i < rows; i++){
		for(j = 0; j < cols; j++){
			ptr1[i][j] = rand() % 10;
            printf("%d ", ptr1[i][j]);
		}
        printf("\n");
	}

	ptr2 = make2darray(rows, cols);
    for(i = 0;i < rows; i++){
		for(j = 0; j < cols; j++){
			ptr2[i][j] = ptr1[j][i];	
		}
	}

    for(i = 0;i < rows; i++){
		for(j = 0; j < cols; j++){
            printf("%d ", ptr2[i][j]);
		}
        printf("\n");
	}
    return 0;
}
