#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10 //Define o número máximo de caracteres das strings;

typedef struct {
    char letras[10];
} elemento;

void insertionSort (elemento *A, int n, long int *cmp, long int *mov);

int main() {
  int i, j, k = 1;
  long int cont_cmp, cont_mov;
  elemento * v;
  FILE *f_teste, *f_new;
  char file_teste[100] = "teste_a.txt";
  char file_new[100] = "resultinho6.txt";

  f_new = fopen(file_new, "w");
  fprintf(f_new, "Testes com %s!\n",file_teste);
  fprintf(f_new, "///------ Ordenação com Insertion - Versão 1 ------///\n\n");
/* Lendo arquivo e executando os testes: */
  for(i = 0; i <= 10; i++) {
    cont_cmp = 0; cont_mov = 0;
    f_teste = fopen(file_teste, "r");
    v = malloc(sizeof(elemento) * (k * 250));
    for(j = 0; j < (k * 250); j++) {
        fscanf(f_teste, "%s", v[j].letras);
    }
    insertionSort(v, (k * 250), &cont_cmp, &cont_mov);
    printf("Teste %d Certo!\n", (i + 1));
    fprintf(f_new, "TESTE %d - %d Palavras\n", (i + 1), (k * 250));
    fprintf(f_new, "\nNúmero de Comparações:..... %ld\n", cont_cmp);
    fprintf(f_new, "Número de Movimentações:.... %ld\n\n", cont_mov);

    /*for(int j = (k - 1)*250; j < (k - 1)*250 + 100; j++) {
        fprintf(f_new, "%s\n", v[j].letras);
    }*/

    free(v);
    fclose(f_teste);
    k = k * 2;
  }
  fclose(f_new);
  return 0;
}

void insertionSort (elemento *A, int n, long int *cmp,long int *mov) {
  int i, j;
  elemento chave;
  /* a cada iteração, teremos o vetor A[1..i] ordenado */
  /* começamos de A[i], porque obviamente o vetor em A[0..0] está 
     trivialmente ordenado */
     
  for (i = 1; i < n; i++) {
    chave = A[i];
    j = i - 1;

    /* encontra a posicao correta de chave (A[i])
       no vetor A[0..i-1] */
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