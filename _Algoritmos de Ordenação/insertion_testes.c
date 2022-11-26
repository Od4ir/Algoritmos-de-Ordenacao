/*--------------------------------------------------
/// INSERTION_SORT - Versão Testes ///
> Versão com Entrada / Saída em arquivos <

Algoritmo de ordenação adaptado para ordenar strings. 
No arquivo de saída será impresso o nome do arquivo 
utilizado como entrada, o número de palavras em cada
teste e quantas comparações e movimentações foram fei-
tas dentro do vetor de palavras. 
---------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char letras[11];
} elemento;

void insertionSort (elemento *A, int n, long int *cmp, long int *mov);

int main() {
  int i, j, k = 1;
  long int cont_cmp, cont_mov;
  elemento * v;
  FILE *f_teste, *f_new;
  char file_teste[100] = "teste_p.txt";
  char file_new[100] = "insertion_result_par.txt";

  f_new = fopen(file_new, "w");
  fprintf(f_new, "Testes com %s!\n",file_teste);
  fprintf(f_new, "///-------- Ordenação com Insertion_Sort --------///\n\n");

  /* Lendo arquivo e executando os testes: */
  for(i = 0; i <= 10; i++) {
    cont_cmp = 0; cont_mov = 0;
    f_teste = fopen(file_teste, "r");
    v = malloc(sizeof(elemento) * (k * 250));

    for(j = 0; j < (k * 250); j++) {
      fscanf(f_teste, "%s", v[j].letras);
    }

    insertionSort(v, (k * 250), &cont_cmp, &cont_mov);
    printf("Teste %d ok!\n", i + 1);
    fprintf(f_new, "TESTE %d - %d Palavras\n", (i + 1), (k * 250));
    fprintf(f_new, "\nNumero de Comparacoes:..... %ld\n", cont_cmp);
    fprintf(f_new, "Numero de Movimentações:.... %ld\n\n", cont_mov);

    /*for(int j = (k - 1)*250; j < (k - 1)*250 + 100; j++) {
        fprintf(f_new, "%s\n", v[j].letras);
    }
    fprintf(f_new, "\n"); */

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