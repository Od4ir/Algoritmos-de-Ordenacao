/*--------------------------------------------------
PROGRAMA PARA FABRICAR ARQUIVOS DE TESTE
NO FORMATO .txt

O programa recebe um inteiro n e abre um dos seguin-
tes arquivos:
- words_ordenadas.txt;
- words_aleatorias.txt;
E devolve um arquivo nomeado pelo usuário com n pa-
lavras selecionadas a partir do arquivo escolhido. 
----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento {
    char letras[11];
} elemento;

int main (){
    char nome_teste[100] = "teste_od1.txt";
    char fonte_escolhida[100] = "teste_od.txt";
    elemento word_aux;
    FILE *f_new, *file_words;
    int numero_palavras, i, aux, not_this, op;

    printf("Digite o numero de palavras que deseja no seu arquivo teste: \n");
    scanf("%d", &numero_palavras);

    f_new = fopen(nome_teste, "w");
    file_words = fopen(fonte_escolhida, "r");
    fprintf(f_new, "%d\n", numero_palavras);

    i = 0;
    while(i < numero_palavras) { 
        not_this = 0;
        fscanf(file_words, "%s", word_aux.letras);
        int dif = strlen(word_aux.letras);
        if(dif >= 10) 
            dif = 10;

        for(int j = 0; j < dif; j++) {
            fprintf(f_new, "%c", word_aux.letras[j]);
        }
        fprintf(f_new, "\n");
        i++;
    }
            
    fclose(f_new);
    fclose(file_words);
    return 0;
}