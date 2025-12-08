#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    char s1[] = "34";
    char s2[] = "7";    
    char s3[] = "23";
    char s4[] = "32";
    char s5[] = "5";

    pid_t pid = fork();

    if (pid == 0) {
        execl("/home/ryan/CSE321/lab_assessment_2_practice/sort", "sort", s1, s2, s3, s4, s5, NULL);
        perror("Child Exec failed"); 
    } 
    else if (pid > 0) {
        wait(NULL);
        execl("/home/ryan/CSE321/lab_assessment_2_practice/oddeven", "oddeven", s1, s2, s3, s4, s5, NULL);
        perror("Parent Exec failed");
    } 
    else {
        perror("Fork failed");
        return 1;
    }
    return 0;
}