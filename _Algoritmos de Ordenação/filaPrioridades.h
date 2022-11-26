typedef struct {
    char letras[10];
} elemento;

void CorrigeHeapDescendo(elemento *v, int n, int i, long int *cmp, long int *mov);
void ConstroiHeap (elemento *v, int n, long int *cmp, long int *mov);
void troca(elemento *v, int i, int j);


