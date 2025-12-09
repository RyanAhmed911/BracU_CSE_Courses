#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;
    
    pid1 = fork();
    if (pid1 > 0) {
        wait(NULL);
    } else if (pid1 == 0) {
        pid2 = fork();
        if (pid2 > 0) {
            wait(NULL);
            int child_pid = getpid();
            printf("Child Process ID: %d\n", child_pid);
            printf("Grandchild Process ID: %d\n", pid2);
            int result = pid2 % child_pid;
            if (result % 2 == 1) {
                printf("Hello the remainder is ODD\n");
            } else {
                printf("Hello the remainder is EVEN\n");
            }
        } else if (pid2 == 0) {
            // Grandchild process does nothing
        }
    }
}