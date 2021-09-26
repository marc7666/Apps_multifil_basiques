/**
 * @author Marc Cervera Rosell
 * */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct {
    int valor_inicial;
    int valor_final;
} Trango;

int *sumaNPrimers(Trango *trango);

int main() {
    int inferior = 0, superior = 0;
    printf("Escriu el valor inferior del interval: \n");
    scanf("%d", &inferior);
    printf("Escriu el valor superior de l'interval: \n");
    scanf("%d", &superior);

    Trango *estructura;
    estructura = malloc(sizeof(Trango));
    estructura->valor_inicial = inferior;
    estructura->valor_final = superior;
    printf("valor_inicial: %d\n", estructura->valor_inicial);
    printf("valor final: %d\n", estructura->valor_final);

    pthread_t tid;
    int *suma; /*Guardara el resultat de la suma*/
    pthread_create(&tid, NULL, (void *(*)(void *)) sumaNPrimers, estructura);
    pthread_join(tid, (void **) &suma);
    printf("Resultat de la suma = %d\n", *suma);
    exit(0);

}

int *sumaNPrimers(Trango *trango) {
    int sum = 0;
    int *ret;
    printf("Funcio -> valor_inicial = %d\n", trango->valor_inicial);
    printf("Funcio -> valor_final = %d\n", trango->valor_final);
    for (int i = trango->valor_inicial; i <= trango->valor_final; i++) {
        sum = sum + i;
    }
    ret = malloc(sizeof(int));
    *ret = sum;
    return (ret);
}

