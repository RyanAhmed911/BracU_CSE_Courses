#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

char ingredients[3][10] = {"Bread", "Cheese", "Lettuce"};
int table[3] = {0, 0, 0};
int complete = 0;

pthread_mutex_t mutex;
sem_t s_bread_maker;
sem_t s_cheese_maker;
sem_t s_lettuce_maker;
sem_t s_supplier;

void *supplier(void *arg) {
    int n = *((int *)arg);
    for (int i = 0; i < n; i++) {
        sem_wait(&s_supplier);
        pthread_mutex_lock(&mutex);
        
        int missing = rand() % (3) + 1;
        int placed[2];
        int index = 0;
        
        for (int j = 1; j <= 3; j++) {
            if (j != missing) {
                placed[index] = j;
                index++;
            }
        }
    
        table[placed[0] - 1] = placed[0];
        table[placed[1] - 1] = placed[1];
        printf("Supplier places: %s and %s on the table.\n", ingredients[placed[0] - 1], ingredients[placed[1] - 1]);
        
        pthread_mutex_unlock(&mutex);
        
        if (missing == 1) {
            sem_post(&s_bread_maker);
        } else if (missing == 2) {
            sem_post(&s_cheese_maker);
        } else {
            sem_post(&s_lettuce_maker);
        }
    }
    
    sem_wait(&s_supplier);
    complete = 1;
    sem_post(&s_bread_maker);
    sem_post(&s_cheese_maker);
    sem_post(&s_lettuce_maker);
}

void *bread_maker(void *arg) {
    while (1) {
        sem_wait(&s_bread_maker);
        
        if (complete == 1) {
            break;
        }

        pthread_mutex_lock(&mutex);
        
        printf("Maker A picks up Cheese and Lettuce\n");
        table[1] = 0;
        table[2] = 0;
        
        printf("Maker A is making the sandwich...\n");
        
        printf("Maker A finished making the sandwich and eats it\n");
        pthread_mutex_unlock(&mutex);
        
        printf("Maker A signals Supplier\n\n");
        sem_post(&s_supplier); 
    }     
}

void *cheese_maker(void *arg) {
    while (1) {
        sem_wait(&s_cheese_maker);

        if (complete == 1) {
            break;
        }
        
        pthread_mutex_lock(&mutex);

        printf("Maker B picks up Bread and Lettuce\n");
        table[0] = 0;
        table[2] = 0;
        
        printf("Maker B is making the sandwich...\n");
        
        printf("Maker B finished making the sandwich and eats it\n");
        pthread_mutex_unlock(&mutex);
        
        printf("Maker B signals Supplier\n\n");
        sem_post(&s_supplier);
    }
}

void *lettuce_maker(void *arg) {
    while (1) {
        sem_wait(&s_lettuce_maker);

        if (complete == 1) {
            break;
        }

        pthread_mutex_lock(&mutex);
    
        printf("Maker C picks up Bread and Cheese\n");
        table[0] = 0;
        table[1] = 0;
        
        printf("Maker C is making the sandwich...\n");
        
        printf("Maker C finished making the sandwich and eats it\n");
        pthread_mutex_unlock(&mutex);
        
        printf("Maker C signals Supplier\n\n");
        sem_post(&s_supplier);
    }
}

int main(void) {
    pthread_t t[4];
    
    pthread_mutex_init(&mutex, NULL);
    
    sem_init(&s_bread_maker, 0, 0);
    sem_init(&s_cheese_maker, 0, 0);
    sem_init(&s_lettuce_maker, 0, 0);
    sem_init(&s_supplier, 0, 1);
    
    srand(time(NULL));

    int n;
    printf("Enter number of times a supplier places ingredients: ");
    scanf("%d", &n);

    
    pthread_create(&t[0], NULL, (void *)supplier, &n);
    pthread_create(&t[1], NULL, (void *)bread_maker, NULL);
    pthread_create(&t[2], NULL, (void *)cheese_maker, NULL);
    pthread_create(&t[3], NULL, (void *)lettuce_maker, NULL);
        
    for (int j = 0; j < 4; j++) {
        pthread_join(t[j], NULL);
    }
    
    
    pthread_mutex_destroy(&mutex);
    sem_destroy(&s_bread_maker);
    sem_destroy(&s_cheese_maker);
    sem_destroy(&s_lettuce_maker);
    sem_destroy(&s_supplier);
    return 0;
}

