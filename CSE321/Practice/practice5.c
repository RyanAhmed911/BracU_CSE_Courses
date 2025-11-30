#include <stdio.h>
#include <string.h>

int main(void) {
    char buffer[100];
    printf("Enter a string: ");
    scanf("%s", buffer);

    char *start;
    char *end;

    start = buffer;
    end = buffer + strlen(buffer) - 1;

    int isPalindrome = 1;

    while (start < end) {
        if (*start != *end) {
            isPalindrome = 0;
            break;
        } else {
            start++;
            end--;
        }
    }
    
    if (isPalindrome == 1) {
        printf("Palindrome\n");
    } else {
        printf("Not palindrome\n");
    }
    return 0;
}