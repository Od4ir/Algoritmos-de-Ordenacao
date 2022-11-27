/*--------------------------------------------------
/// MERGESORT ///
> Versão com Entrada / Saída no próprio terminal <

Algoritmo de ordenação adaptado para ordenar strings. 
Basta digitar o número de elementos que deseja orde-
nar, isto é, o número de palavras e depois digitar as
palavras. 

O resultado ordenado será impresso no terminal. 
---------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letras[11];
} elemento;

void intercala(int p, int q, int r, elemento *v, int *cmp, int *mov);
void mergeSort (int p, int r, elemento *v, int *cmp, int *mov);
void printando(elemento *v, int n, int cmp, int mov);

int main() {
  int i, n, cont_cmp = 0, cont_mov = 0;
  elemento *v;

  printf("\n///-------- Ordenacao com Mergesort --------///\n\n");

  printf(">>> Digite o numero de elementos: ");
  scanf("%d",&n);
  v = malloc (n * sizeof(elemento));
  
  printf(">>> Digite os elementos: \n");
  for (i = 0; i < n; i++) { 
        scanf("%s", v[i].letras);
  }
  
  mergeSort(0, n-1, v, &cont_cmp, &cont_mov);
  printando(v, n, cont_cmp, cont_mov);

  free(v);
  return 0;
}

void intercala (int p, int q, int r, elemento *v, int *cmp, int *mov)  {
  int n1, n2;
  elemento *A, *B;                     
  int i, j, k;

  n1 = q - p + 1;
  n2 = r - q;
  
  A = malloc (n1 * sizeof (elemento));      
  B = malloc (n2 * sizeof (elemento));      

  for (i = 0; i < n1; i++) { 
    A[i] = v[p+i];
    *mov = *mov + 1;
  }

  for (i = 0; i < n2; i++) { 
    B[i] = v[q+1 + i];
    *mov = *mov + 1;
  }

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

void mergeSort (int p, int r, elemento *v, int *cmp, int *mov) {
  int q;
  if (p < r) {                 
    q = (p + r)/2;         
    mergeSort(p, q, v, cmp, mov);       
    mergeSort(q+1, r, v, cmp, mov);       
    intercala(p, q, r, v, cmp, mov);    
  }
}

void printando(elemento *v, int n, int cmp, int mov) {
    int i;

    printf("\n>>> Lista ordenada: \n");
    for(i = 0; i < n; i++) {
        printf("%dº : ", i + 1);
        printf("%s\n", v[i].letras);
    }
    printf("\nNumero de Comparacoes:..... %d\n", cmp);
    printf("Numero de Movimentacoes:....%d", mov);
}   
