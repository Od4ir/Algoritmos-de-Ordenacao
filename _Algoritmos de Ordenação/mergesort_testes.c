/*--------------------------------------------------
/// MERGESORT - Versão Testes ///
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

void intercala(int p, int q, int r, elemento *v, long int *cmp, long int *mov);
void mergeSort (int p, int r, elemento *v, long int *cmp, long int *mov);

int main() {
int i, j, k = 1;
  long int cont_cmp, cont_mov;
  elemento * v;
  FILE *f_teste, *f_new;
  char file_teste[100] = "teste_a.txt";
  char file_new[100] = "resultinho5.txt";

  f_new = fopen(file_new, "w");
  fprintf(f_new, "Testes com %s!\n",file_teste);
  fprintf(f_new, "///-------- Ordenação com Mergesort --------///\n\n");

  /* Lendo arquivo e executando os testes: */
  for(i = 0; i <= 10; i++) {
    cont_cmp = 0; cont_mov = 0;
    f_teste = fopen(file_teste, "r");
    v = malloc(sizeof(elemento) * (k * 250));
    for(j = 0; j < (k * 250); j++) {
        fscanf(f_teste, "%s", v[j].letras);
    }
    mergeSort(0, (k * 250) - 1, v, &cont_cmp, &cont_mov);
    fprintf(f_new, "TESTE %d - %d Palavras\n", (i + 1), (k * 250));
    fprintf(f_new, "\nNumero de Comparacoes:..... %ld\n", cont_cmp);
    fprintf(f_new, "Numero de Movimentações:....... %ld\n\n", cont_mov);

    /*for(int j = (k - 1)*250; j < (k - 1)*250 + 20; j++) {
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

void intercala (int p, int q, int r, elemento *v, long int *cmp, long int *mov)  {
  int n1, n2;
  elemento *A, *B;                     
  int i, j, k;

  n1 = q - p + 1;
  n2 = r - q;
  
  A = malloc (n1 * sizeof (elemento));      
  B = malloc (n2 * sizeof (elemento));      

  for (i = 0; i < n1; i++)
    A[i] = v[p+i];

  for (i = 0; i < n2; i++)
    B[i] = v[q+1 + i];

  i = 0, j = 0;
  k = p;
  while (i < n1 && j < n2) {     
    *cmp = *cmp + 1;           
    if(strcmp(A[i].letras, B[j].letras) <= 0) {       
      v[k] = A[i++];  
      *mov = *mov + 1;
    }
    else { 
      v[k] = B[j++];
      *mov = *mov + 1;
    }
    k++;
  }

  while (i < n1) { 
    v[k++] = A[i++];   
    *mov = *mov + 1;  
  }    
  while (j < n2) { 
    v[k++] = B[j++];
    *mov = *mov + 1;
  }

  free(A);
  free(B);
}

void mergeSort (int p, int r, elemento *v, long int *cmp, long int *mov) {
  int q;
  if (p < r) {                 
    q = (p + r)/2;         
    mergeSort(p, q, v, cmp, mov);       
    mergeSort(q+1, r, v, cmp, mov);       
    intercala(p, q, r, v, cmp, mov);    
  }
}
 
