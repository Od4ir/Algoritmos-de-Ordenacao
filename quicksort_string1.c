#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char letras[10];
} elemento;

void troca (elemento *v, int i, int j){
  elemento aux;
  aux = v[j];
  v[j] = v[i];
  v[i] = aux;
}

int compara_elemento(elemento elem1, elemento elem2) {
  int i;
  // Comparando os caracteres:
  i = 0;
  while(i < 10) {
      if(elem1.letras[i] < elem2.letras[i]) {
        return 1;
      }
      else if(elem1.letras[i] > elem2.letras[i]) {
        return 0;
      }
      i++;
  }
  // Strings iguais:
  return 1;
}

int particiona (elemento *v, int ini, int fim) {
  int i, j;
  elemento pivo;

  pivo = v[fim];
  i = ini;

  for(j = ini; j < fim; j++) {
    if(compara_elemento(v[j], pivo)) {
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
  int i, n, op;
  elemento * v;
  FILE *f;
  char file_name[100];
  int cont = 0;

  printf("Digite qual teste deseja realizar: \n");
  printf(" >> 1 - Vetor Ordenado\n >> 2 - Vetor Aleatório\n >> 3 - Vetor Invertido\n >> 4 - Vetor Parcialmente Ordenado\n");

  scanf("%d", &op);
  if(op == 1) {
    char file_name[] = "teste_o.txt";
  }
  else if(op == 2) {
    char file_name[] = "teste_a.txt";
  }

  f = fopen(file_name, "r");
   fscanf(f, "%d", &n);
  printf("Digite o número de elementos: ");
  scanf("%d",&n);
  v = malloc (n * sizeof(elemento));
  
  printf("Pegando os elementos: \n");
 
  for (i = 0; i < n; i++) { 
    fscanf(f, "%s", v[i].letras);
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