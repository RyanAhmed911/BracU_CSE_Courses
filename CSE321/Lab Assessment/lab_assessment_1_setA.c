#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    char buffer[100];
    printf("Enter the marks of the students separated by spaces: ");
    getchar();
    fgets(buffer, sizeof(buffer), stdin);
    
    int index = 0;
    char marks_list[n][10];
    int marks_index = 0;

    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == ' ' || buffer[i] == '\n') {
            marks_list[marks_index][index] = '\0';
            marks_index++;
            index = 0;
        }
        else {
            marks_list[marks_index][index] = buffer[i];
            index++;
        }
    }

    int a_count = 0;
    int b_count = 0;
    int c_count = 0;
    int d_count = 0;
    int f_count = 0;

    for (int i = 0; i < n; i++) {
        int mark = atoi(marks_list[i]);
        if (mark >= 80) {
            a_count++;
        }
        else if (70 <= mark && mark < 80) {
            b_count++;
        }
        else if (60 <= mark && mark < 70) {
            c_count++;
        }
        else if (50 <= mark && mark < 60) {
            d_count++;
        }
        else {
            f_count++;
        }
    }
    printf("A grade count = %d\n", a_count);
    printf("B grade count = %d\n", b_count);
    printf("C grade count = %d\n", c_count);
    printf("D grade count = %d\n", d_count);
    printf("F grade count = %d\n", f_count);

    return 0;
}