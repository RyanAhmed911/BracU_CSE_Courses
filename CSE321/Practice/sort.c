#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = argc - 1;
    int arr[n];
    int sorted_arr[n];
    
    for (int i = 1; i < argc; i++) {
        arr[i-1] = atoi(argv[i]);
    }
    for (int i = 0; i < n; i++) {
        int max = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] != -1) {
                if (arr[j] >= max) {
                max = arr[j];
            }
        }
        sorted_arr[i] = max;
        }
        for (int k = 0; k < n; k++) {
            if (arr[k] == max) {
                arr[k] = -1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");
    return 0;
}