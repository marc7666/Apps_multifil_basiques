/**
 * @author Marc Cervera Rosell
 * */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 100

int *showDigits(char *car);

int main() {
    pthread_t tid1, tid2;
    int *dig1, *dig2;
    pthread_create(&tid1, NULL, (void *(*)(void *)) showDigits, "1");
    pthread_create(&tid2, NULL, (void *(*)(void *)) showDigits, "2");
    pthread_join(tid1, (void **) &dig1);
    pthread_join(tid2, (void **) &dig2);
    printf("\nFirst thread. Number of characters printed: %d\n", *dig1);
    printf("Second thread. Number of characters printed: %d\n", *dig2);
    free(dig1);
    free(dig2);
    exit(0);
}

int *showDigits(char *car) {
    int *ret, i;
    for (i = 0; i < MAX; i++) {
        write(1, car, 1);
    }
    ret = malloc(sizeof(int));
    *ret = i;
    return (ret);
}