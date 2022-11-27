/* ---------------------------------------------------------------
Este programa lê algum dos vetores de teste com 256 mil palavras e
inverte a ordem da lista.
------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letras[10];
} word;

int main () {
    FILE *f_new, *f_old;
    char file_old[100] = "teste_poc1.txt";
    char file_new[100] = "teste_pod1.txt";
    word *words;

    words = malloc(sizeof(word) * 256000);
    f_new = fopen(file_new, "w");
    f_old = fopen(file_old, "r");

    for(int i = 0; i < 256000; i++) {
        fscanf(f_old, "%s", words[i].letras);
    }

    for(int i = 256000 - 1; i > 0; i--) {
        fprintf(f_new, "%s\n", words[i].letras);
    }

    fclose(f_new);
    fclose(f_old);
    free(words);
    return 0;
}