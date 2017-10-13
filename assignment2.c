#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int i = 0,j = 0, flag = 0, count, x;
    printf("please enter the count of the array:\n");
    scanf("%d", &count);
    if(count > 10) {
        printf("ERROR");
	    exit(0);
    }

    int array[count][count];
    //set every elements 0
    for(i = 0; i < count ; i++){
	    for(j = 0; j < count; j++) {
            array[i][j] = 0;
	        }
    }
    i = 0;
    j = 0;

    //set array to the Counterclockwise
    for(x = 0; x < count * count; x++) {
	    switch (flag) {
		case 0:
			array[i][j] = x + 1;
            //out of range or the next index have value, change the dirction
			if(array[i + 1][j] != 0 || i >= count - 1){
				flag = 1;
				j++;
			}else i++; //The next number is 0 and in the range
			break;
		case 1:
			array[i][j] = x + 1;
			if(array[i][j + 1] != 0 || j >= count - 1){
				flag = 2;
				i--;
			}else j++;
			break;
		case 2:
			array[i][j] = x + 1;
			if(array[i - 1][j] != 0 || i <= 0){
				flag = 3;
				j--;
			}else i--;
			break;
		case 3:
			array[i][j] = x + 1;
			if(array[i][j - 1] != 0 || j <= 0){
				flag = 0;
				i++;
			}else j--;
			break;
		default:
			break;
	    }
    }

    //the ClockWise
    printf("The ClockWise is\n");
    for(i = 0; i < count; i++) {
	    for (j = 0; j < count; j++) {
		printf("%4d ", array[j][i]);
	}
	printf("\n\n");
    }
    //the Counterclockwise
    printf("The Counterclockwise is\n");
    for(i = 0; i < count; i++) {
	    for(j = 0; j < count; j++) {
		    printf("%4d ", array[i][j]);
	    }
	    printf("\n\n");
    }
    return 0;
}
