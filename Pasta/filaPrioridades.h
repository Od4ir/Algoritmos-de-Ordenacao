typedef int item;

typedef struct {
    int tamanho;
    int capacidade;
    item *elemento;
} heap;

void CorrigeHeapDescendo(heap H, int i);
void ConstroiHeap (heap H, int n);
void troca(heap H, int i, int j);


