#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int seat_available = 100;
sem_t seat_sem;

void *buy_tickets(void *arg) {
    int ticket_amount = *((int *)arg);
    sem_wait(&seat_sem);
    printf("Buying %d tickets...\n", ticket_amount);
    seat_available -= ticket_amount;
    printf("Tickets bought: %d, Seats remaining: %d\n", ticket_amount, seat_available);
    sem_post(&seat_sem);
    return NULL;
}

int main() {
    sem_init(&seat_sem, 0, 1);
    while (1) {
        int ticket_amount;
        printf("Enter number of tickets to buy (0 to exit): ");
        scanf("%d", &ticket_amount);
        if (ticket_amount == 0) {
            break;
        }
        if (ticket_amount > seat_available) {
            printf("Not enough seats available. Seats remaining: %d\n", seat_available);
            continue;
        } else {
            pthread_t t1;
            pthread_create(&t1, NULL, buy_tickets, &ticket_amount);
            pthread_join(t1, NULL);
        }
    }
}