#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11 //Define o número máximo de caracteres das strings;

typedef struct {
    char letras[10];
} elemento;

void intercala(int p, int q, int r, elemento *v, int *cmp);
void mergeSort (int p, int r, elemento *v, int *cmp);
void printando(elemento *v, int n, int cmp);

int main() {
  int i, n, cont_cmp = 0;
  elemento *v;

  printf("\n///------ Ordenação com Mergesort - Versão 1 ------///\n\n");

  printf(">>> Digite o número de elementos: ");
  scanf("%d",&n);
  v = malloc (n * sizeof(elemento));
  
  printf(">>> Digite os elementos: \n");
  for (i = 0; i < n; i++) { 
        scanf("%s", v[i].letras);
  }
  
  mergeSort(0, n-1, v, &cont_cmp);
  printando(v, n, cont_cmp);

  free(v);
  return 0;
}

void intercala (int p, int q, int r, elemento *v, int *cmp)  {
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
    if(strcmp(A[i].letras, B[j].letras) <= 0)                   //(compara_elemento(A[i], B[j]))   //A[i] <= B[j])
      v[k] = A[i++];  
    else
      v[k] = B[j++];
    k++;
  }

  while (i < n1)
    v[k++] = A[i++];         
  while (j < n2)
    v[k++] = B[j++];

  free(A);
  free(B);
}

void mergeSort (int p, int r, elemento *v, int *cmp) {
  int q;
  if (p < r) {                 
    q = (p + r)/2;         
    mergeSort(p, q, v, cmp);       
    mergeSort(q+1, r, v, cmp);       
    intercala(p, q, r, v, cmp);    
  }
}

void printando(elemento *v, int n, int cmp) {
    int i;

    printf("\n>>> Lista ordenada: \n");
    for(i = 0; i < n; i++) {
        printf("%dº : ", i + 1);
        printf("%s\n", v[i].letras);
    }
    printf("\nNúmero de Comparações:..... %d\n", cmp);
}   
