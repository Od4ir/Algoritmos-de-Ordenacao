#include <stdio.h>
#include <stdlib.h>
#include "filaPrioridades.h"

void quicksort(item *v, int n) {
    ConstroiHeap(v, n);
    for(i = 1; i < n; i++) {
        troca(v[i], v[n]);
        CorrigeHeapDescendo(v, n-i, i);
    }
}

int main () {

}