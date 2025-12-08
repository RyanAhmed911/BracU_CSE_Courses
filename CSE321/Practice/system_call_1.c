#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    fd = open(argv[1], O_RDWR | O_CREAT, 0644);

    if (fd != -1) {
        printf("%s opened with read/write access\n", argv[1]);
        while (1) {
            char buffer[80];
            printf("Enter a string to write to the file (type '-1' to quit): ");
            fgets(buffer, sizeof(buffer), stdin);
            if (buffer[0] == '-' && buffer[1] == '1' && buffer[2] == '\n') {
                break;
            } else {
                int i = 0;
                while (buffer[i] != '\0') {
                    write(fd, &buffer[i], 1);
                    i++;
                }
            }
        }
        close(fd);
        return 0;
    } else {
        printf("%s not opened\n", argv[1]);
        return 1;
    }
}