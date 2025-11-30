#include <stdio.h>
#include <string.h>

int main(void) {
    char email[100];
    printf("Enter your email address: ");
    scanf("%s", email);

    char* token = strtok(email, "@");
    token = strtok(NULL, "@");
    
    if (strcmp(token,"sheba.xyz") == 0) {
        printf("Email address is okay.\n");
    } else if (strcmp(token, "kaaj.com") == 0) {
        printf("Email address is outdated.\n");
    }   else {
        printf("Email address is not recognized.\n");
    }
    return 0;
}