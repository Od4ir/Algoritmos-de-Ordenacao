/* -----------------------------------------------
>>> HEAPSORT - Versão Testes <<< 

Heapsort versão testes - Ordenação de strings.
------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaPrioridades.h"

void heapsort(elemento *v, int n, long int *cmp, long int *mov);

int main () {
    int i, j, k = 1;
    long int cont_cmp, cont_mov;
    elemento * v;
    FILE *f_teste, *f_new;
    char file_teste[100] = "teste_a.txt";
    char file_new[100] = "resultinho.txt";

    f_new = fopen(file_new, "w");
    fprintf(f_new, "Testes com %s!\n",file_teste);
    fprintf(f_new, "///------ Ordenação com Heapsort ------///\n\n");

    /* Lendo arquivo e executando os testes: */
    for(i = 0; i <= 10; i++) {
        cont_cmp = 0; cont_mov = 0;
        f_teste = fopen(file_teste, "r");
        v = malloc(sizeof(elemento) * (k * 250 + 1));
        for(j = 1; j < (k * 250) + 1; j++) {
            fscanf(f_teste, "%s", v[j].letras);
        }
        heapsort(v, (k * 250), &cont_cmp, &cont_mov);
        printf("Teste %d certo!\n", i + 1);
        fprintf(f_new, "TESTE %d - %d Palavras\n", (i + 1), (k * 250));
        fprintf(f_new, "\nNúmero de Comparações:..... %ld\n", cont_cmp);
        fprintf(f_new, "Número de Movimentações:.......... %ld\n\n", cont_mov);

        for(int j = (k - 1)*250; j < (k - 1)*250 + 100; j++) {
            fprintf(f_new, "%s\n", v[j].letras);
        }

        free(v);
        fclose(f_teste);
        k = k * 2;
    }
    fclose(f_new);
    return 0;
}

void heapsort(elemento *v, int n, long int *cmp, long int *mov) {
    ConstroiHeap(v, n, cmp, mov);
    for(int i = n; i > 1; i--) {
        *mov = *mov + 1;
        troca(v, 1, i);  //(&v[1], &v[i]);
        CorrigeHeapDescendo(v, i - 1, 1, cmp, mov);
    }
}
