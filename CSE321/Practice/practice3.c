#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char password[100];
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    
    int length = strlen(password) -1;
    bool lowercase = false;
    bool uppercase = false;
    bool digit = false;
    bool specialChar = false;

    for (int i = 0; i < length; i++) {
        if ('a' <= password[i] && password[i] <= 'z') {
            lowercase = true;
        } else if ('A' <= password[i] && password[i] <= 'Z') {
            uppercase = true;
        } else if ('0' <= password[i] && password[i] <= '9') {
            digit = true;
        } else if ( password[i] == '_' || password[i] == '$' || password[i] == '#' || password[i] == '@') {
            specialChar = true;
        } 
    }

    if (lowercase == true && uppercase == true && digit == true && specialChar == true) {
        printf("OK");
    } else {
        if (lowercase == false) {
            printf("Lowercase letter is missing. ");
        }
        if (uppercase == false) {
            printf("Uppercase letter is missing. ");
        }
        if (digit == false) {
            printf("Digit is missing. ");
        }
        if (specialChar == false) {
            printf("Special character is missing. ");
        }
    }
    printf("\n");
    return 0;
}