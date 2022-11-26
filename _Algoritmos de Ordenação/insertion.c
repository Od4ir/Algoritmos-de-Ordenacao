/*--------------------------------------------------
/// INSERTION_SORT ///
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

typedef struct {
  char letras[11];
} elemento;

void insertionSort (elemento *A, int n, long int *cmp, long int *mov);
void printando(elemento *v, int n, long int cmp, long int mov);

int main() {
  int i, n;
  long int cont_cmp = 0, cont_mov = 0;
  elemento * v;

  printf("\n///-------- Ordenação com Insertion_Sort --------///\n\n");

  printf(">>> Digite o numero de elementos: ");
  scanf("%d",&n);
  v = malloc (n * sizeof(elemento));
  
  printf(">>> Digite os elementos: \n");
  for (i = 0; i < n; i++) { 
        scanf("%s", v[i].letras);
  }
  insertionSort(v, n, &cont_cmp, &cont_mov);
  printando(v, n, cont_cmp, cont_mov);
  
  free(v);
  return 0;
}

void insertionSort (elemento *A, int n, long int *cmp,long int *mov) {
  int i, j;
  elemento chave;
     
  for (i = 1; i < n; i++) {
    chave = A[i];
    j = i - 1;

    *cmp = *cmp + 1;
    while (j >= 0 && (strcmp(A[j].letras, chave.letras) > 0)) {   
      *cmp = *cmp + 1;
      A[j + 1] = A[j];
      *mov = *mov + 1;
      j = j - 1;
    }
    A[j + 1] = chave;
    *mov = *mov + 1;
  }
}

void printando(elemento *v, int n, long int cmp, long int mov) {
    int i;

    printf("\n>>> Lista ordenada: \n");
    for(i = 0; i < n; i++) {
        printf("%dº : ", i + 1);
        printf("%s\n", v[i].letras);
    }
    printf("\nNumero de Comparacoes:..... %ld\n", cmp);
    printf("Numero de Movimentações:.... %ld\n\n", mov);
}   