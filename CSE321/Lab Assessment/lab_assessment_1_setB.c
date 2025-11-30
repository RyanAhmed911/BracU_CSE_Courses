#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *file = fopen("lab_assessment_1_setB_input.txt", "r");
    
    char first_line[100];
    char second_line[100];

    fgets(first_line, sizeof(first_line), file);
    fgets(second_line, sizeof(second_line), file);

    int n = atoi(first_line);
    
    char numbers_char[n][10];
    int index = 0;
    int numbers_count = 0;
    
    for (int i = 0; i < strlen(second_line); i++) {
        if (second_line[i] == ' ' || second_line[i] == '\n') {
            numbers_char[numbers_count][index] = '\0';
            numbers_count++;
            index = 0;
        }
        else {
            numbers_char[numbers_count][index] = second_line[i];
            index++;
        }
    }

    int even_sum = 0;
    int odd_sum = 0;
    int even_count = 0;
    int odd_count = 0;

    for (int i = 0; i < n; i++) {
        int number = atoi(numbers_char[i]);
        if (number % 2 == 0) {
            even_sum += number;
            even_count++;
        }
        else {
            odd_sum += number;
            odd_count++;
        }
    }

    printf("Even sum = %d\n", even_sum);
    printf("Odd sum = %d\n", odd_sum);
    printf("Even count = %d\n", even_count);
    printf("Odd count = %d\n", odd_count);

    fclose(file);
    return 0;
}