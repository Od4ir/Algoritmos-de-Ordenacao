/*--------------------------------------------------
/// QUICKSORT 2 ///
> Versao com Entrada / Saída no próprio terminal <

Algoritmo de ordenação adaptado para ordenar strings. 
Basta digitar o número de elementos que deseja orde-
nar, isto é, o número de palavras e depois digitar as
palavras. 

O resultado ordenado será impresso no terminal. 
---------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char letras[11];
} elemento;

void troca (elemento *v, int i, int j, int *mov);
int particiona (elemento *v, int ini, int fim, int *cmp, int *mov);
void quicksort (elemento *v, int ini, int fim, int *cmp, int *mov);
void printando(elemento *v, int n, int cmp, int mov);

int main() {
  int i, n, cont_cmp = 0, cont_mov = 0;
  elemento * v;

  printf("\n///-------- Ordenacao com Quicksort - Versao 2 --------///\n\n");

  printf(">>> Digite o numero de elementos: ");
  scanf("%d",&n);
  v = malloc (n * sizeof(elemento));
  
  printf(">>> Digite os elementos: \n");
  for (i = 0; i < n; i++) { 
        scanf("%s", v[i].letras);
  }
  quicksort(v, 0, n - 1, &cont_cmp, &cont_mov);
  printando(v, n, cont_cmp, cont_mov);

  free(v);
  return 0;
}

void troca (elemento *v, int i, int j, int *mov){
  elemento aux;
  aux = v[j];
  v[j] = v[i];
  v[i] = aux;
  *mov = *mov + 1;
}

int particiona (elemento *v, int ini, int fim, int *cmp, int *mov) {
  int i, j;
  elemento pivo;

  i = ini;
  j = fim + 1;
  pivo = v[ini];

  while(1) {
    *cmp = *cmp + 1;
    while(strcmp(v[++i].letras, pivo.letras) < 0) {  
        if(i == fim) break;
        *cmp = *cmp + 1;
    }
    *cmp = *cmp + 1;
    while(strcmp(v[--j].letras, pivo.letras) > 0) {   
        if(j == ini) break;
        *cmp = *cmp + 1;     
    }
    
    if(i >= j) 
        break;
    troca(v, i, j, mov);
  }
  troca(v, ini, j, mov);
  return j;
}

void quicksort (elemento *v, int ini, int fim, int *cmp, int *mov) {
  int x;
  if (ini < fim){
    x = particiona(v, ini, fim, cmp, mov);
    quicksort(v, ini, x - 1, cmp, mov);
    quicksort(v, x + 1, fim, cmp, mov);
  }
}

void printando(elemento *v, int n, int cmp, int mov) {
    int i;

    printf("\n>>> Lista ordenada: \n");
    for(i = 0; i < n; i++) {
        printf("%dº : ", i + 1);
        printf("%s\n", v[i].letras);
    }
    printf("\nNumero de Comparacoes:........ %d\n", cmp);
    printf("Numero de Movimentacoes:...... %d\n\n", mov);

}   
