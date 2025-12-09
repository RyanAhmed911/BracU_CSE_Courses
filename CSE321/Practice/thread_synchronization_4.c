#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t checkin_slots;
pthread_mutex_t immigration_counter;
sem_t train;

void *passenger_journey(void *arg) {
    sem_wait(&checkin_slots);
    printf("Passenger checking in...\n");
    sleep(1);
    printf("Passenger checked in\n");
    sem_post(&checkin_slots);
    pthread_mutex_lock(&immigration_counter);
    printf("Passenger passing through immigration...\n");
    sleep(2);
    printf("Passenger cleared through immigration\n");
    pthread_mutex_unlock(&immigration_counter);
    sem_wait(&train);
    printf("Passenger boarding the train to the plane...\n");
    sleep(3);
    printf("Passenger on the plane\n");
    sem_post(&train);
    return NULL;
}

int main(void) {
    pthread_t threads[6];
    pthread_mutex_init(&immigration_counter, NULL);
    sem_init(&checkin_slots, 0, 15);
    sem_init(&train, 0, 4); 
    for (int i = 0; i < 6; i++) {
        pthread_create(&threads[i], NULL, passenger_journey, NULL);
    }
    for (int i = 0; i < 6; i++) {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&checkin_slots);
    sem_destroy(&train);
    pthread_mutex_destroy(&immigration_counter);
    return 0;
}