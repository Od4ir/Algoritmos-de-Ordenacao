#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char letras[10];
} elemento;

void troca (elemento *v, int i, int j, int *trc);
int particiona (elemento *v, int ini, int fim, int *trc, int *cmp);
void quicksort (elemento *v, int ini, int fim, int *trc, int *cmp);
void printando(elemento *v, int n, int trc, int cmp);

int main() {
  int i, n, cont_trc = 0, cont_cmp = 0;
  elemento * v;

  printf("\n///------ Ordenação com Quicksort - Versão 2 ------///\n\n");

  printf(">>> Digite o número de elementos: ");
  scanf("%d",&n);
  v = malloc (n * sizeof(elemento));
  
  printf(">>> Digite os elementos: \n");
  for (i = 0; i < n; i++) { 
        scanf("%s", v[i].letras);
  }
  quicksort(v, 0, n - 1, &cont_trc, &cont_cmp);
  printando(v, n, cont_trc, cont_cmp);

  free(v);
  return 0;
}

void troca (elemento *v, int i, int j, int *trc){
  elemento aux;
  aux = v[j];
  v[j] = v[i];
  v[i] = aux;
  *trc = *trc + 1;
}

int particiona (elemento *v, int ini, int fim, int *trc, int *cmp) {
  int i, j;
  elemento pivo;

  pivo = v[fim];
  i = ini;

  for(j = ini; j < fim; j++) {
    *cmp = *cmp + 1;
    if(strcmp(v[j].letras, pivo.letras) < 0) { 
        troca(v, i, j, trc);
        i++;
    }
  }
  troca(v, i, fim, trc);
  return i;
}

void quicksort (elemento *v, int ini, int fim, int *trc, int *cmp) {
  int x;
  if (ini < fim){
    x = particiona(v, ini, fim, trc, cmp);
    quicksort(v, ini, x - 1, trc, cmp);
    quicksort(v, x + 1, fim, trc, cmp);
  }
}

void printando(elemento *v, int n, int trc, int cmp) {
    int i;

    printf("\n>>> Lista ordenada: \n");
    for(i = 0; i < n; i++) {
        printf("%dº : ", i + 1);
        printf("%s\n", v[i].letras);
    }
    printf("\nNúmero de Comparações:..... %d\n", cmp);
    printf("Número de Trocas:.......... %d\n\n", trc);

}   
