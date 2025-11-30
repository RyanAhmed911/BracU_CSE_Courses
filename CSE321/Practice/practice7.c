#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int perfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    if (sum == num) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    FILE *input_file = fopen("practice7_input.txt", "r");
    char lower_bound_char[10];
    char upper_bound_char[10];
    
    fgets(lower_bound_char, sizeof(lower_bound_char), input_file);
    fgets(upper_bound_char, sizeof(upper_bound_char), input_file);
    
    fclose(input_file);
    
    int lower_bound = atoi(lower_bound_char);
    int upper_bound = atoi(upper_bound_char);
    
    FILE *output_file = fopen("practice7_output.txt", "w");

    for (int i = lower_bound; i <= upper_bound; i++) {
        if (perfect(i) == 1) {
            fprintf(output_file, "%d\n", i);
        } 
    }
    fclose(output_file);
    return 0;
}