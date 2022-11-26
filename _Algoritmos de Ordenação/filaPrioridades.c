#include "filaPrioridades.h"
#include <string.h>

void troca (elemento *v, int i, int j){
    elemento aux;
    aux = v[j];
    v[j] = v[i];
    v[i] = aux;
}

void CorrigeHeapDescendo(elemento *v, int n, int i, long int *cmp, long int *mov) {
    int maior = i;

    /* Considerando as duas comparações feitas a seguir: */
    *cmp = *cmp + 2;

    if((2*i <= n)&&(strcmp(v[2*i].letras, v[maior].letras) > 0)) {         
        maior = 2*i;
    }
    if((2*i + 1 <= n)&&(strcmp(v[2*i + 1].letras, v[maior].letras) > 0)) {  
        maior = 2*i + 1;
    }
    if(maior != i) { 
        *mov = *mov + 1;
        troca(v, i, maior);    
        CorrigeHeapDescendo(v,n, maior, cmp, mov);
    }
}

void ConstroiHeap (elemento *v, int n, long int *cmp, long int *mov) {
    for(int i = n/2; i >= 1; i--)
        CorrigeHeapDescendo(v, n, i, cmp, mov);
}
