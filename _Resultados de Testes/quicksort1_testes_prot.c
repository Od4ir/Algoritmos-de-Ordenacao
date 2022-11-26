/* QUICKSORT VERSÃO 1 - TESTES */
/* Escolhendo pivo como o primeiro elemento e utilizando versão 1 do particiona. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char letras[11];
} elemento;

void troca (elemento *v, int i, int j, long int *cont){
  elemento aux;
  strcpy(aux.letras, v[j].letras);
  strcpy(v[j].letras, v[i].letras);
  strcpy(v[i].letras, aux.letras);
  *cont = *cont + 1;
}

int particiona (elemento *v, int ini, int fim, long int *cont_trc, long int *cont_cmp) {
  int i, j;
  elemento pivo;

  pivo = v[ini];
  i = ini;

  for(j = ini; j < fim; j++) {
    *cont_cmp = *cont_cmp + 1;
    if (strcmp(v[j].letras, pivo.letras) < 0) {    
        troca(v, i, j, cont_trc);
        i++;
    }
  }
  troca(v, i, fim, cont_trc);
  return i;
}

void quicksort (elemento *v, int ini, int fim, long int *cont_trc, long int *cont_cmp) {
  int x;
  if (ini < fim){
    x = particiona(v, ini, fim, cont_trc, cont_cmp);
    quicksort(v, ini, x - 1, cont_trc, cont_cmp);
    quicksort(v, x + 1, fim, cont_trc, cont_cmp);
  }
}

int main() {
  long int cont_trc = 0, cont_cmp = 0;
  elemento * v;
  FILE *f_teste, *f_new;
  char file_teste[100] = "teste_a.txt";
  char file_new[100] = "result_alet.txt";
  int i, j, k = 1;
    
  f_new = fopen(file_new, "w");
  fprintf(f_new, "Testes com %s!\n",file_teste);

  for(i = 0; i <= 10; i++) {
    cont_cmp = cont_trc = 0;
    f_teste = fopen(file_teste, "r");
    v = malloc(sizeof(elemento) * (k * 250));
    for(j = 0; j < k * 250; j++) {
      if(!(fscanf(f_teste, "%s", v[j].letras)))
        j--;

    }
    quicksort(v, 0, (k*250) - 1, &cont_trc, &cont_cmp);
    /*printf("Teste com %d palavras: \n  Comparações: %ld\n  Trocas: %ld\n\n", k*250, cont_cmp, cont_trc); */
    fprintf(f_new, "Teste com %d palavras: \n  Comparações: %ld\n  Trocas: %ld\n\n", k*250, cont_cmp, cont_trc);

    free(v);
    fclose(f_teste);
    k = k*2;
  }
return 0;
}

/*gcc -Wall -ansi -pedantic -O2 */