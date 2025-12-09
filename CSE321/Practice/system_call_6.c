#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    char buffer[] = "Hello from Parent Process\n";
    char read_buffer[100];
    
    fd = open("test2.txt", O_RDWR | O_CREAT, 0644);
    printf("Parent process writing to file...\n");
    write(fd, buffer, strlen(buffer));
    printf("%s", buffer);
    
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process reading from file...\n");
        lseek(fd, 0, SEEK_SET);
        read(fd, read_buffer, sizeof(read_buffer));
        printf("Content read: %s", read_buffer);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("Fork failed");
        return 1;
    }
}