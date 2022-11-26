#include "filaPrioridades.h"
#include <string.h>
#include <stdio.h>

void troca (elemento *v, int i, int j){
    elemento aux;
    aux = v[j];
    v[j] = v[i];
    v[i] = aux;
}

void CorrigeHeapDescendo(elemento *v, int n, int i, long int *cmp, long int *mov) {
    int maior = i;

    *cmp = *cmp + 1;
    if((2*i <= n)&&(strcmp(v[2*i].letras, v[maior].letras) > 0)) {          //v[2*i] > v[maior])) {
        maior = 2*i;
    }
    *cmp = *cmp + 1;
    if((2*i + 1 <= n)&&(strcmp(v[2*i + 1].letras, v[maior].letras) > 0)) {  //(v[2*i + 1] > v[maior])) {
        maior = 2*i + 1;
    }
    if(maior != i) { 
        *mov = *mov + 1;
        troca(v, i, maior);    //(&v[i], &v[maior]);
        CorrigeHeapDescendo(v,n, maior, cmp, mov);
    }
}

void ConstroiHeap (elemento *v, int n, long int *cmp, long int *mov) {
    for(int i = n/2; i >= 1; i--)
        CorrigeHeapDescendo(v, n, i, cmp, mov);
}
