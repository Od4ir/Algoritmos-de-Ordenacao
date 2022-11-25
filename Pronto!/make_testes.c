#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento {
    char letras[10];
} elemento;

/* PROGRAMA PARA FABRICAR ARQUIVOS DE TESTE NO FORMATO .txt

 O programa recebe um inteiro n e abre um dos seguintes arquivos:
 - words_ordenadas.txt;
 - words_aleatorias.txt;
 E devolve um arquivo nomeado pelo usuário com n palavras selecio-
 nadas a partir do arquivo escolhido. 

 */

int main (){
    char nome_teste[100], *fonte_escolhida;
    elemento word_aux;
    FILE *f_new, *file_words;
    int numero_palavras, i, aux, not_this, op;

    printf("Digite o número de palavras que deseja no seu arquivo teste: \n");
    scanf("%d", &numero_palavras);

    printf("Digite o nome do arquivo .txt que deseja salvar as palavras: \n");
    scanf("%s", nome_teste);

    printf("Digite de qual arquivo fonte deseja obter suas palavras: \n");
    printf(" \n>>> 1 - words_ordenadas.txt");
    printf(" \n>>> 2 - words_aleatorias.txt\n\n");

    scanf("%d", &op);
    if(op == 1) { 
        fonte_escolhida = "words_ordenadas.txt";
    }
    else if(op == 2) { 
        fonte_escolhida = "words_aleatorias.txt";
    }

    f_new = fopen(nome_teste, "w");
    file_words = fopen(fonte_escolhida, "r");
    fprintf(f_new, "%d\n", numero_palavras);

    i = 0;
    while(i < numero_palavras) { 
        not_this = 0;
        fscanf(file_words, "%s", word_aux.letras);
        for(aux = 0; ((aux < strlen(word_aux.letras))&&(!not_this)); aux++) {
            int auxx = word_aux.letras[aux];
            if(!((auxx > 64 && auxx < 91)||(auxx > 96 && auxx < 123))) { 
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