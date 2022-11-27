/*--------------------------------------------------
/// QUICKSORT 1 - Versão Testes ///
> Versão com Entrada / Saída em arquivos <

Algoritmo de ordenação adaptado para ordenar strings. 
No arquivo de saída será impresso o nome do arquivo 
utilizado como entrada, o número de palavras em cada
teste e quantas comparações e movimentações foram fei-
tas dentro do vetor de palavras. 
---------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char letras[11];
} elemento;

void troca (elemento *v, int i, int j, unsigned long int *mov);
int particiona (elemento *v, int ini, int fim, unsigned long int *cmp, unsigned long int *mov);
void quicksort (elemento *v, int ini, int fim, unsigned long int *cmp, unsigned long int *mov);

int main() {
  int i, j, k = 1024;
  unsigned long int cont_mov, cont_cmp;
  elemento * v;
  FILE *f_teste, *f_new;
  char file_teste[100] = "teste_a.txt";
  char file_new[100] = "quicksort_result_a.txt";

  f_new = fopen(file_new, "w");
  fprintf(f_new, "Testes com %s!\n",file_teste);
  fprintf(f_new, "///-------- Ordenacao com Quicksort - Versao 1 --------///\n\n");

  /*Se o teste for feito com algum dos seguintes arquivos:

    "teste_oc.txt";
    "teste_poc.txt";
    "teste_od.txt";
    "teste_pod.txt";

  Altere a iteração do for abaixo de "i <= 10" para "i < 10"; */

  /* Lendo arquivo e executando os testes: */
  for(i = 0; i <= 10; i++) {
    cont_cmp = 0; cont_mov = 0;
    f_teste = fopen(file_teste, "r");
    v = malloc(sizeof(elemento) * (k * 250));
    for(j = 0; j < (k * 250); j++) {
        fscanf(f_teste, "%s", v[j].letras);
    }
    quicksort(v, 0, (k * 250) - 1, &cont_cmp, &cont_mov);
    printf("Teste %d ok! com %d!\n", (i + 1), (k * 250));
    fprintf(f_new, "TESTE %d - %d Palavras\n", (i + 1), (k * 250));
    fprintf(f_new, "\nNumero de Comparacoes:..... %ld\n", cont_cmp);
    fprintf(f_new, "Numero de Movimentacoes:.......... %ld\n\n", cont_mov);

    for(int j = (k - 1)*250; j < (k - 1)*250 + 10; j++) {
        fprintf(f_new, "%s\n", v[j].letras);
    }
    fprintf(f_new, "\n"); 

    free(v);
    fclose(f_teste);
    k = k * 2;
  }
  fclose(f_new);
  return 0;
}

void troca (elemento *v, int i, int j, unsigned long int *mov){
  elemento aux;
  aux = v[j];
  v[j] = v[i];
  v[i] = aux;
  *mov = *mov + 1;
}

int particiona (elemento *v, int ini, int fim, unsigned long int *cmp, unsigned long int *mov) {
  int i, j;
  elemento pivo;

  pivo = v[fim];
  i = ini;

  for(j = ini; j < fim; j++) {
    *cmp = *cmp + 1;
    if(strcmp(v[j].letras, pivo.letras) < 0) { 
        troca(v, i, j, mov);
        i++;
    }
  }
  troca(v, i, fim, mov);
  return i;
}

void quicksort (elemento *v, int ini, int fim, unsigned long int *cmp, unsigned long int *mov) {
  int x;
  if (ini < fim){
    x = particiona(v, ini, fim, cmp, mov);
    quicksort(v, ini, x - 1, cmp, mov);
    quicksort(v, x + 1, fim, cmp, mov);
  }
}
