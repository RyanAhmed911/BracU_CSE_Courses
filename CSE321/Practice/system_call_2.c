#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    pid_t pid1;
    pid_t pid2;
    int status1;
    int status2;

    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid1 == 0) {
        pid2 = fork();
        if (pid2 < 0) {
            perror("Fork failed");
            return 1;
        } else if (pid2 == 0) {
            printf("I am grandchild\n");
        } else {
            wait(&status2);
            printf("I am child\n");
        }
    } else {
        wait(&status1);
        printf("I am parent\n");
    }
}