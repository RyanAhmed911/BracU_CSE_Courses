#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid1, pid2;
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    pid1 = fork();
    if (pid1 < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid1 == 0) {
        int product = a * b;
        printf("Child process: The product of %d and %d is %d\n", a, b, product);
        if (product % 2 == 0) {
            pid2 = fork();
            if (pid2 < 0) {
                printf("Fork failed\n");
                return 1;
            } else if (pid2 == 0) {
                int factorial = 1;
                if (a > b) {
                    for (int i = 1; i <= b; i++) {
                        factorial *= i;
                    }
                    printf("Grandchild process: Factorial of %d is %d\n", b, factorial);
                } else {
                    for (int i = 1; i <= a; i++) {
                        factorial *= i;
                    }
                    printf("Grandchild process: Factorial of %d is %d\n", a, factorial);
                }
            } else {
                wait(NULL);
            }
        } else {
            int factorial = 1;
            if (a > b) {
                for (int i = 1; i <= a; i++) {
                    factorial *= i;
                }
                printf("Child process: Factorial of %d is %d\n", a, factorial);
            }
            else {
                for (int i = 1; i <= b; i++) {
                    factorial *= i;
                }
                printf("Child process: Factorial of %d is %d\n", b, factorial);
            }
        }
    } else {
        wait(NULL);
        printf("Parent process: End of process\n");
    }
}