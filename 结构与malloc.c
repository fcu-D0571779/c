#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define COMPARE(x,y) (((x)<(y))?-1:((x)==(y))?0:1)

//copyright MercurYao
//D0571779
//指标，结构
//Note：交换结构，换两个结构的指标
//Note：'x' != "x"
//Note： char a[5] = {'a', 'b', 'c'}
//Note:  char b[5] = "abc"
//Note: b包含\0，可以用strlen来计算长度
//Note: 在读文件的时候读完一行就输出会输出原来记忆体里面的东西

typedef struct Student{
    char name[10];
    int points;
}stu;

void selection_sort(stu array[], int n){
    int i, j, min;
    stu temp;
    for(i = 0; i < 30; i++){
        min = i;
        for(j = i + 1; j < 30; j++){
            if(array[j].points < array[min].points){
                min = j;
            }
        }
        SWAP(array[min],array[i],temp);
    }
}

int binary_search(stu list[], int searchnum, int left, int right){
    int middle;
    if(left <= right){
      middle = (left + right) / 2;
      switch (COMPARE(list[middle].points, searchnum)) {
        case -1: return binary_search(list, searchnum, middle + 1, right);
        case 0: return list[middle].points;
        case 1: return binary_search(list, searchnum, left, middle - 1);
        default : break;
      }
    }
}

int main(int argc, char const *argv[]) {
    stu StudentList[30];
    FILE *fp1 = fopen("stu.txt", "r");
    int i = 0, n = 30;
    while (!feof(fp1)) {
        fscanf(fp1, "%s", StudentList[i].name);
        fscanf(fp1, "%d", &StudentList[i].points);
        i++;
    }
    fclose(fp1);

    //selection_sort
    selection_sort(StudentList, n);
    for (i = 0; i < 30; i++) {
        printf("%s\n", StudentList[i].name);
        printf("%d\n", StudentList[i].points);
    }

    int score, count, left = 0, right = 30;

	while(1){
        printf("please enter the number you want to search\n");
        scanf("%d", &score);
        count = binary_search(StudentList, score, left, right);
        if(count != 0)printf("find out the %d\n", count);
        else {
            printf("can't find the %d\n", score);
            exit(0);
        }
	}

    return 0;
}
