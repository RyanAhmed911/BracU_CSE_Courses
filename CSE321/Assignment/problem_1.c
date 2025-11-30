#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int *fibonacci_sequence_generator(int *v);
void *fibonacci_value_search(void *sequence);
int *t_ret;

int main(void) {
    pthread_t t1;
    pthread_t t2;

    int n;

    do {
        printf("Enter the term of fibonacci sequence:\n");
        scanf("%d",&n);
    } while (n < 0 || n > 40);
    
    pthread_create(&t1, NULL, (void *)fibonacci_sequence_generator, &n);
    pthread_join(t1, &t_ret);

    t_ret[n + 1] = -1;

    pthread_create(&t2, NULL, (void *)fibonacci_value_search, (void *)t_ret);
    pthread_join(t2, NULL);

    free(t_ret);
    return 0;
}

int *fibonacci_sequence_generator(int *v) {
    int *a = malloc(sizeof(int) * (*v + 2));
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= *v; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    
    return a; 
}

void *fibonacci_value_search(void *sequence) {
    int m;
    int *fibonacci_sequence = sequence;
    int count = 0;

    do {
        printf("How many numbers you are willing to search?:\n");
        scanf("%d",&m);
    } while (m < 1);

    int search_values[m];
    for (int i = 0; i < m; i++) {
        printf("Enter search %d:\n", i + 1);
        scanf("%d", &search_values[i]);
    }
    
    for (int i = 0; fibonacci_sequence[i] != -1; i++) {
        printf("a[%d] = %d\n", i, fibonacci_sequence[i]);
        count++;
    }

    for (int i = 0; i < m; i++) {
        if (search_values[i] >= 0 && search_values[i] <= count) {
            printf("result of search #%d = %d\n", i + 1, fibonacci_sequence[search_values[i]]);
        } else {
            printf("result of search #%d = -1\n", i + 1);
        }
    }
}
