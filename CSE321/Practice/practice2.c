#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char buffer[100];
    
    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);
    
    int length = strlen(buffer) - 1;
    char result[100];
    int index = 0;
    int space_count = 0;
    
    for (int i = 0; i < length; i++) {
        if (buffer[i] != ' ') {
            result[index] = buffer[i];
            index++;
            space_count = 0;
        } else {
            if (space_count == 0) {
                result[index] = buffer[i];
                index++;
                space_count = 1;
            }
        }
    }
    result[index] = '\0';

    printf("Processed string: %s\n", result);
    return 0;
}