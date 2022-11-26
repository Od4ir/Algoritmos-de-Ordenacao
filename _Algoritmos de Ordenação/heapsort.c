/* -----------------------------------------------
>>> HEAPSORT <<< 

Heapsort versão 1 - Ordenação de strings.
------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaPrioridades.h"

void heapsort(elemento *v, int n, long int *cmp, long int *mov);
void printando(elemento *v, int n, long int cmp, long int mov);

int main () {
    int i, n;
    long int cont_cmp = 0, cont_mov = 0;
    elemento * v;

    printf("\n///----------- Ordenação com Heapsort -----------///\n\n");

    printf(">>> Digite o número de elementos: ");
    scanf("%d",&n);
    n = n + 1;
    v = malloc (n * sizeof(elemento));
        
    printf(">>> Digite os elementos: \n");
    for (i = 1; i < n; i++) { 
        scanf("%s", v[i].letras);
    }
    heapsort(v, n - 1, &cont_cmp, &cont_mov);
    printando(v, n, cont_cmp, cont_mov);
    
    free(v);
    return 0;
}

void heapsort(elemento *v, int n, long int *cmp, long int *mov) {
    ConstroiHeap(v, n, cmp, mov);
    for(int i = n; i > 1; i--) {
        *mov = *mov + 1;
        troca(v, 1, i);  //(&v[1], &v[i]);
        CorrigeHeapDescendo(v, i - 1, 1, cmp, mov);
    }
}

void printando(elemento *v, int n, long int cmp, long int mov) {
    int i;

    printf("\n>>> Lista ordenada: \n");
    for(i = 1; i < n; i++) {
        printf("%dº : ", i);
        printf("%s\n", v[i].letras);
    }
    printf("\nNúmero de Comparações:..... %ld\n", cmp);
    printf("Número de Movimentações:.... %ld\n\n", mov);
}  