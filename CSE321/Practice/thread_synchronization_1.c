#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int shared_array[100];
int idx = 0;
pthread_mutex_t lock;

void *number_reader(void *arg) {
    pthread_mutex_lock(&lock);
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    shared_array[idx] = num;
    idx++;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[4];
    pthread_mutex_init(&lock, NULL);
    int result = 1;
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, number_reader, NULL);
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < idx; i++) {
        result = result * shared_array[i];
    }
    printf("Product of all numbers: %d\n", result);
    pthread_mutex_destroy(&lock);
    return 0;
}