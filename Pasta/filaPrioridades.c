#include "filaPrioridades.h"
#include <string.h>
#include <stdio.h>

void troca (elemento *v, int i, int j){
  elemento aux;
  aux = v[j];
  v[j] = v[i];
  v[i] = aux;
}

void CorrigeHeapDescendo(elemento *v, int n, int i) {
    int maior = i;

    if((2*i <= n)&&(strcmp(v[2*i], v[maior]) == 1)) {          //v[2*i] > v[maior])) {
        maior = 2*i;
    }
    if((2*i + 1 <= n)&&(strcmp(v[2*i + 1], v[maior]) == 1)) {  //(v[2*i + 1] > v[maior])) {
        maior = 2*i + 1;
    }
    if(maior != i) { 
        troca(v, i, maior);    //(&v[i], &v[maior]);
        CorrigeHeapDescendo(v,n, maior);
    }
}

void ConstroiHeap (elemento *v, int n) {
    for(int i = n/2; i >= 1; i--)
        CorrigeHeapDescendo(v, n, i);
}
