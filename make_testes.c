#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letras[10];
} elemento;

int main (){
    char nome_teste[] = "teste1_a.txt";
    FILE *f_new, *file_words;
    elemento word_aux;
    int numero_palavras, i = 0, aux, not_this;
    scanf("%d", &numero_palavras);

    f_new = fopen(nome_teste, "w");
    file_words = fopen("words_ordenadas.txt", "r");
    fprintf(f_new, "%d\n", numero_palavras);

    while(i < numero_palavras) { 
        not_this = 0;
        fscanf(file_words, "%s", word_aux.letras);
        for(aux = 0; ((aux < strlen(word_aux.letras))&&(!not_this)); aux++) {
            if(word_aux.letras[aux] == '.' || word_aux.letras[aux] == ',' || word_aux.letras[aux] == '?' || word_aux.letras[aux] == '"' || word_aux.letras[aux] == '!' || word_aux.letras[aux] == ';' || word_aux.letras[aux] == '(' || word_aux.letras[aux] == ')' || word_aux.letras[aux] == '-')  {
                not_this = 1;
            }
        } 
        if(strlen(word_aux.letras) <= 10 && !not_this) {
            fprintf(f_new, "%s\n", word_aux.letras);
            i++;
        }
    }
            
    fclose(f_new);
    fclose(file_words);
    return 0;
}