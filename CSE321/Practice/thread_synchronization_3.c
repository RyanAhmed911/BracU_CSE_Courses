#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int stock = 100;
int max_stock = 200;

pthread_mutex_t lock;

void *stock_update(void *arg) {
    pthread_mutex_lock(&lock);
    int amount;
    printf("Enter amount to add to stock: ");
    scanf("%d", &amount);
    if (stock + amount > max_stock) {
        printf("Cannot add %d to stock. Exceeds maximum stock limit of %d.\n", amount, max_stock);
        pthread_mutex_unlock(&lock);
        return NULL;
    } else {
        stock += amount;
        printf("Stock updated by %d, new stock: %d\n", amount, stock);
        pthread_mutex_unlock(&lock);
        return NULL;
    }
}

void *sales(void *arg) {
    pthread_mutex_lock(&lock);
    int amount;
    printf("Enter amount to sell from stock: ");
    scanf("%d", &amount);
    if (amount > stock) {
        printf("Cannot sell %d from stock. Not enough stock available.\n", amount);
        pthread_mutex_unlock(&lock);
        return NULL;
    } else {
        stock -= amount;
        printf("Stock sold by %d, new stock: %d\n", amount, stock);
        pthread_mutex_unlock(&lock);
        return NULL;
    }
}

int main(void) {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&t1, NULL, stock_update, NULL);
    pthread_create(&t2, NULL, sales, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}