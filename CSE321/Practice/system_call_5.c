#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t parent_pid = getpid();
    pid_t child_pid, grandchild1_pid, grandchild2_pid, grandchild3_pid;

    printf("Parent process ID: %d\n", parent_pid);

    child_pid = fork();
    if (child_pid == 0) {
        printf("Child process ID: %d\n", getpid());
        grandchild1_pid = fork();
        if (grandchild1_pid == 0) {
            printf("Grand Child process ID: %d\n", getpid()); 
        }
        else {
            grandchild2_pid = fork();
            if (grandchild2_pid == 0) {
                printf("Grand Child process ID: %d\n", getpid()); 
            }
            else {
                grandchild3_pid = fork();
                if (grandchild3_pid == 0) {
                    printf("Grand Child process ID: %d\n", getpid()); 
                }
            }
        }
    }
    wait(NULL); 
    wait(NULL); 
    wait(NULL); 
    wait(NULL); 
    return 0;
}