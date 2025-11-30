#include <stdio.h>

int main(void){
    int x, y;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);

    if (x > y){
        printf("%d\n", x-y);
    }
    else if (x < y){
        printf("%d\n", x+y);
    }
    else{
        printf("%d\n", x*y);
    }
    return 0;
}