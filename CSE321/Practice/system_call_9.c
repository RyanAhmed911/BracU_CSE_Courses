#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int number;
    pid_t pid1, pid2;
    printf("Enter an integer: ");
    scanf("%d", &number);

    pid1 = fork();
    if (pid1 > 0) {
        wait(NULL);
        printf("Parent process:End of process\n");
    } else if (pid1 == 0) {
        for (int i = 0; i <= number; i++) {
            if (i % 2 == 1) {
                int square = i * i;
                printf("Square of %d is %d\n", i, square);
            } else {
                pid2 = fork();
                if (pid2 > 0) {
                    wait(NULL);
                } else if (pid2 == 0) {
                    int cube = i * i * i;
                    printf("Cube of %d is %d\n", i, cube);
                exit(0);
                }
            }
        }
    }
}