#include <stdio.h>
#include <stdlib.h>
#include "filaPrioridades.h"

void troca(heap H, int i, int j) {
    item aux;
    aux = H.elemento[i];
    H.elemento[i] = H.elemento[j];
    H.elemento[j] = aux;
}

void CorrigeHeapDescendo(heap H, int i) {
    int maior = i;

    if((2*i <= H.tamanho)&&(H.elemento[2*i] > H.elemento[maior])) {
        printf("Aqui estamos! i: %d\n", i);
        maior = 2*i;
    }
    if((2*i + 1 <= H.tamanho)&&(H.elemento[2*i + 1] > H.elemento[maior])) {
        printf("Aqui estamos 2! i: %d\n", i);
        maior = 2*i + 1;
    }
    if(maior != i) { 
        troca(H, i, maior);
        //troca(H.elemento[i], H.elemento[maior]);
        printf("Troca feita entre %d e %d!\n\n", H.elemento[i], H.elemento[maior]);
        CorrigeHeapDescendo(H, maior);
    }
}

void ConstroiHeap (heap H, int n) {
    H.tamanho = n;
    int i;
    printf("Cheguei aqui, e esse é o i >> %d\n", n/2);
    for(i = n/2; i >= 1; i--) {
        printf("Por enquanto, tudo certo! i >> %d\n", i);
        CorrigeHeapDescendo(H, i);
    }
    for(i = 1; i < n + 1; i++) {
        printf("%d ", H.elemento[i]);
    }
}

int main (){
    heap H;
    int n;

    printf("Digite o número de elementos do vetor: \n");
    scanf("%d", &n);
    H.elemento = malloc(sizeof(item) * (n + 2));

    printf("Digite os elementos: \n");
    for(int i = 1; i < n + 1; i++) {
        scanf("%d", &H.elemento[i]);
    }
    ConstroiHeap(H, n);

    free(H.elemento);
    return 0;
}