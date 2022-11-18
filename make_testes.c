#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char letras[10];
} elemento;

int main (){
    char nome_teste[100] = "teste3.txt";
    FILE *f_new, *file_words;
    elemento *words;
    int numero_palavras;

    scanf("%d", &numero_palavras);

    words = malloc(sizeof(elemento) * numero_palavras);

    f_new = fopen(nome_teste, "w");
    file_words = fopen("words.txt", "r");
    fprintf(f_new, "%d\n", numero_palavras);

    for(int i = 0; i < numero_palavras; i++) {
        fscanf(file_words, "%s", words[i].letras);
        fprintf(f_new, "%s\n", words[i].letras);
    }

    fclose(f_new);
    fclose(file_words);
    return 0;
}