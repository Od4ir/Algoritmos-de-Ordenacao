#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char letras[11];
} elemento;

void troca (elemento *v, int i, int j){
  elemento aux;
  aux = v[j];
  v[j] = v[i];
   v[i] = aux;
}


int particiona (elemento *v, int ini, int fim) {
  int i, j;
  elemento pivo;

  pivo = v[fim];
  i = ini;

  for(j = ini; j < fim; j++) {
    if(strcmp(v[j].letras, pivo.letras) > 0) {
        troca(v, i, j);
        i++;
    }
  }
  troca(v, i, fim);
  return i;
}

void quicksort (elemento *v, int ini, int fim) {
  int x;
  if (ini < fim){
    x = particiona(v, ini, fim);
    quicksort(v, ini, x - 1);
    quicksort(v, x + 1, fim);
  }
}

int main() {
  int i, n;
  elemento * v;

  printf("Digite o número de elementos: ");
  scanf("%d",&n);
  v = malloc (n * sizeof(elemento));
  
  printf("Digite os elementos: \n");
  for (i = 0; i < n; i++) { 
        scanf("%s", v[i].letras);
  }

  quicksort(v, 0, n - 1);
  printf("\n\n");

  printf(" >>> Lista ordenada: \n");
  for(i = 0; i < n; i++) {
    printf("%dº : ", i + 1);
    for(int j = 0; j < 10; j++) {
        printf("%c", v[i].letras[j]);
    }
    printf("\n");
  }
  
  free(v);
  return 0;
}