#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11 //Define o número máximo de caracteres das strings;

typedef struct {
    char letras[10];
} elemento;

void intercala(int p, int q, int r, elemento *v, long int *cmp, long int *atb);
void mergeSort (int p, int r, elemento *v, long int *cmp, long int *atb);

int main() {
int i, j, k = 1;
  long int cont_cmp, cont_atb;
  elemento * v;
  FILE *f_teste, *f_new;
  char file_teste[100] = "teste_a.txt";
  char file_new[100] = "resultinho5.txt";

  f_new = fopen(file_new, "w");
  fprintf(f_new, "Testes com %s!\n",file_teste);
  fprintf(f_new, "///------ Ordenação com Mergesort - Versão 1 ------///\n\n");

  /* Lendo arquivo e executando os testes: */
  for(i = 0; i <= 10; i++) {
    cont_cmp = 0; cont_atb = 0;
    f_teste = fopen(file_teste, "r");
    v = malloc(sizeof(elemento) * (k * 250));
    for(j = 0; j < (k * 250); j++) {
        fscanf(f_teste, "%s", v[j].letras);
    }
    mergeSort(0, (k * 250) - 1, v, &cont_cmp, &cont_atb);
    fprintf(f_new, "TESTE %d - %d Palavras\n", (i + 1), (k * 250));
    fprintf(f_new, "\nNúmero de Comparações:..... %ld\n", cont_cmp);
    fprintf(f_new, "Número de Atribuições:....... %ld\n\n", cont_atb);

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

void intercala (int p, int q, int r, elemento *v, long int *cmp, long int *atb)  {
  int n1, n2;
  elemento *A, *B;                     
  int i, j, k;

  n1 = q - p + 1;
  n2 = r - q;
  
  A = malloc (n1 * sizeof (elemento));      
  B = malloc (n2 * sizeof (elemento));      

  for (i = 0; i < n1; i++) { 
    A[i] = v[p+i];
    *atb = *atb + 1;
  }

  for (i = 0; i < n2; i++) { 
    B[i] = v[q+1 + i];
    *atb = *atb + 1;
  }

  i = 0, j = 0;
  k = p;
  while (i < n1 && j < n2) {     
    *cmp = *cmp + 1;           
    if(strcmp(A[i].letras, B[j].letras) <= 0)                   //(compara_elemento(A[i], B[j]))   //A[i] <= B[j])
      v[k] = A[i++];  
    else
      v[k] = B[j++];
    k++;
    *atb = *atb + 1;
  }

  while (i < n1) { 
    v[k++] = A[i++];  
    *atb = *atb + 1;  
  }     
  while (j < n2) { 
    v[k++] = B[j++];
    *atb = *atb + 1;
  }

  free(A);
  free(B);
}

void mergeSort (int p, int r, elemento *v, long int *cmp, long int *atb) {
  int q;
  if (p < r) {                 
    q = (p + r)/2;         
    mergeSort(p, q, v, cmp, atb);       
    mergeSort(q+1, r, v, cmp, atb);       
    intercala(p, q, r, v, cmp, atb);    
  }
}
 
