/*--------------------------------------------------
/// QUICKSORT 1 ///
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
int particiona (elemento *v, int ini, int fim, int *mov, int *cmp);
void quicksort (elemento *v, int ini, int fim, int *mov, int *cmp);
void printando(elemento *v, int n, int mov, int cmp);

int main() {
    int i, n, cont_mov = 0, cont_cmp = 0;
    elemento * v;
    FILE *f_new, *f_old;
    char file_old[100] = "teste_o.txt";
    char file_new[100] = "teste_oc.txt";

    v = malloc(sizeof(elemento) * 256000);
    f_new = fopen(file_new, "w");
    f_old = fopen(file_old, "r");

    for(int i = 0; i < 256000; i++) {
        fscanf(f_old, "%s", v[i].letras);
    }

    quicksort(v, 0, 256000 - 1, &cont_mov, &cont_cmp);

    for(int i = 0; i < 256000; i++) {
        fprintf(f_new, "%s\n", v[i].letras);
    }

    //printando(v, n, cont_mov, cont_cmp);
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

int particiona (elemento *v, int ini, int fim, int *mov, int *cmp) {
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

void quicksort (elemento *v, int ini, int fim, int *mov, int *cmp) {
  int x;
  if (ini < fim){
    x = particiona(v, ini, fim, mov, cmp);
    quicksort(v, ini, x - 1, mov, cmp);
    quicksort(v, x + 1, fim, mov, cmp);
  }
}

void printando(elemento *v, int n, int mov, int cmp) {
    int i;

    printf("\n>>> Lista ordenada: \n");
    for(i = 0; i < n; i++) {
        printf("%dº : ", i + 1);
        printf("%s\n", v[i].letras);
    }
    printf("\nNumero de Comparacoes:........ %d\n", cmp);
    printf("Numero de Movimentações:...... %d\n\n", mov);

}   
