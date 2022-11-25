#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char letras[10];
} elemento;

void troca (elemento *v, int i, int j, long int *trc);
int particiona (elemento *v, int ini, int fim, long int *trc, long int *cmp);
void quicksort (elemento *v, int ini, int fim, long int *trc, long int *cmp);

int main() {
  int i, j, k = 1;
  long int cont_trc, cont_cmp;
  elemento * v;
  FILE *f_teste, *f_new;
  char file_teste[100] = "teste_a.txt";
  char file_new[100] = "resultinho1.txt";

  f_new = fopen(file_new, "w");
  fprintf(f_new, "Testes com %s!\n",file_teste);
  fprintf(f_new, "///------ Ordenação com Quicksort - Versão 2 ------///\n\n");

  /* Lendo arquivo e executando os testes: */
  for(i = 0; i <= 10; i++) {
    cont_cmp = 0; cont_trc = 0;
    f_teste = fopen(file_teste, "r");
    v = malloc(sizeof(elemento) * (k * 250));
    for(j = 0; j < (k * 250); j++) {
        fscanf(f_teste, "%s", v[j].letras);
    }
    quicksort(v, 0, (k * 250) - 1, &cont_trc, &cont_cmp);
    fprintf(f_new, "TESTE %d - %d Palavras\n", (i + 1), (k * 250));
    fprintf(f_new, "\nNúmero de Comparações:..... %ld\n", cont_cmp);
    fprintf(f_new, "Número de Trocas:.......... %ld\n\n", cont_trc);

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

void troca (elemento *v, int i, int j, long int *trc){
  elemento aux;
  aux = v[j];
  v[j] = v[i];
  v[i] = aux;
  *trc = *trc + 1;
}

int particiona (elemento *v, int ini, int fim, long int *trc, long int *cmp) {
  int i, j;
  elemento pivo;

  pivo = v[ini];
  i = fim;

  for(j = fim; j > -1; j--) {
    *cmp = *cmp + 1;
    printf("j >> %d\n", j);
    if(strcmp(v[j].letras, pivo.letras) > 0) { 
        troca(v, i, j, trc);
        i--;
        printf("i >>>> %d\n", i);
    }
  }
  printf("Deu ruim?\n");
  troca(v, i, ini, trc);
  return i;
}

void quicksort (elemento *v, int ini, int fim, long int *trc, long int *cmp) {
  int x;
  if (ini < fim){
    x = particiona(v, ini, fim, trc, cmp);
    quicksort(v, ini, x - 1, trc, cmp);
    quicksort(v, x + 1, fim, trc, cmp);
  }
}
