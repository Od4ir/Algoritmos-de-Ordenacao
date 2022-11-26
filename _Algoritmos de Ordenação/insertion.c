#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10 //Define o número máximo de caracteres das strings;

typedef struct {
  char letras[10];
} elemento;

void insertionSort (elemento *A, int n, long int *cmp, long int *mov);
void printando(elemento *v, int n, long int cmp, long int mov);

int main() {
  int i, n;
  long int cont_cmp = 0, cont_mov = 0;
  elemento * v;

  printf("\n///------ Ordenação com InsertionSort - Versão 1 ------///\n\n");

  printf(">>> Digite o número de elementos: ");
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
  /* a cada iteração, teremos o vetor A[1..i] ordenado */
  /* começamos de A[i], porque obviamente o vetor em A[0..0] está trivialmente ordenado */
     
  for (i = 1; i < n; i++) {
    chave = A[i];
    j = i - 1;

    /* encontra a posicao correta de chave (A[i]) no vetor A[0..i-1] */
    *cmp = *cmp + 1;
    while (j >= 0 && (strcmp(A[j].letras, chave.letras) > 0)) {      //(compara_elemento(A[j], chave))) {    //  A[j] > chave) {
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
    printf("\nNúmero de Comparações:..... %ld\n", cmp);
    printf("Número de Movimentações:.... %ld\n\n", mov);
}   