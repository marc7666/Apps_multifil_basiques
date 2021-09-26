/**
 * @author Marc Cervera Rosell
 * */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *fil1(void *vargp);

void *fil2(void *vargp);

int main() {
    pthread_t tid1, tid2;
    printf("Aquest es el fil principal\n");
    pthread_create(&tid1, NULL, fil1, NULL);
    pthread_create(&tid2, NULL, fil2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    exit(0);
}

/*Funcio fil 1*/
void *fil1(void *vargp) {
    printf("Aquest es el fill 1\n");
    return NULL;
}

/*Funcio fill 2*/
void *fil2(void *vargp) {
    printf("Aquest es el fil fill 2\n");
    return NULL;
}
