/* QUICKSORT VERSÃO 1 - DIGITANDO ENTRADA */
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
    printf(">>> Resposta cmp: %d\n", strcmp(v[j].letras, pivo.letras));
    if (strcmp(v[j].letras, pivo.letras) > 0) {  
        printf("Trocando i:%d com j:%d pois i é menor que j\n", i, j); 
        troca(v, i, j, cont_trc);
        i++;
    }
  }
  printf("Trocando i:%d com fim:%d\n\n", i, ini); 
  troca(v, i, ini, cont_trc);
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
  int num_words;
  int i, op;

  printf("/// Ordenando com Quicksort - Versão 1! /// \n\n  Digite o número de palavras: \n  >>> ");
  scanf("%d", &num_words);

  printf("Digite as palavras: \n");

  v = malloc(sizeof(elemento) * num_words);

  for(i = 0; i < num_words; i++) {
    scanf("%s", v[i].letras);
  }

  quicksort(v, 0, num_words, &cont_trc, &cont_cmp);

  printf("  Teste com %d palavras: \n >> Comparações: %ld\n >> Trocas: %ld\n\n", num_words, cont_cmp, cont_trc); 
  printf("Aqui está a lista ordenada: \n");
  for(i = 0; i < num_words; i++) {
    printf("%s\n", v[i].letras);
  }

  free(v);
  return 0;
}