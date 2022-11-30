/*--------------------------------------------------
/// HEAPSORT ///
> Versão com Entrada / Saída no próprio terminal <

Algoritmo de ordenação adaptado para ordenar strings. 
Basta digitar o número de elementos que deseja orde-
nar, isto é, o número de palavras e depois digitar as
palavras. 

O resultado ordenado será impresso no terminal. 
---------------------------------------------------*/

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

    printf("\n///----------- Ordenacao com Heapsort -----------///\n\n");

    printf(">>> Digite o numero de elementos: ");
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
        troca(v, 1, i); 
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
    printf("\nNumero de Comparacoes:..... %ld\n", cmp);
    printf("Numero de Movimentacoes:.... %ld\n\n", mov);
}  