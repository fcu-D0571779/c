#include <stdio.h>
#include <stdlib.h>

typedef struct MyCustomType{
    char name[20];
    char stu_id[15];
    int score;
}stu;

int main(int argc, char const *argv[]) {
    stu student_list[100];
    int choice, i = 0, j, total,flag = 0;
    double average;
    while(1){
        printf("***********************************************\n");
        printf("you have three choices(please input 1,2,3):\n");
        printf("1.insert\n");
        printf("2.print out and sum\n");
        printf("3.exit\n");
        printf("***********************************************\n");
        scanf("%d", &choice);
        printf("***********************************************\n");
        switch (choice) {
            case 1:
                printf("please input the name of %d student\n", i + 1);
                scanf("%s", student_list[i].name);
                printf("please input the id of the %d student\n", i + 1);
                scanf("%s", student_list[i].stu_id);
                printf("please input the score of %d student\n", i + 1);
                scanf("%d", &student_list[i].score);
                flag++;
                break;
            case 2:
                if(i != 0){
                    j = 0;
                    total = 0;
                    for(j = 0; j < flag; j++){
                        printf("--------------------------------------------\n");
                        printf("the %d student\n", flag + 1);
                        printf("%s\n", student_list[j].name);
                        printf("%s\n", student_list[j].stu_id);
                        printf("%d\n", student_list[j].score);
                        total += student_list[j].score;
                        printf("--------------------------------------------\n");
                    }
                    average = total / flag;
                    printf("the average of score of total class %lf\n", average);
                    break;
                }
                printf("please insert a student\n");
                break;
            case 3:
                exit(0);
            default:
                break;
        }
        i++;
    }
    return 0;
}
