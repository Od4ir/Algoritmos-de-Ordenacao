Os códigos:

    heapsort.c
    insertion.c
    mergesort.c
    quicksort1.c
    quicksort2.c

Recebem entrada diretamente no terminal e imprimem o resultado na tela;

Os códigos:

    heapsort_testes.c
    insertion_testes.c
    mergesort_testes.c
    quicksort1_testes.c
    quicksort2_testes.c

Recebem como entrada um arquivo de texto com 256 mil palavras (arquivos 
esses disponíveis na pasta vetores de teste) e realizam de 10 a 11 tes-
tes, começando com 250 palavras e duplicando até atingirem 128 mil pal-
avras ou 256 mil palavras. 
Como saída, escrevem um arquivo informando o número de movimentações e 
comparações de cada um dos testes. 
Para editar quais arquivos devem ser lidos e qual o nome do arquivo de 
saída, basta alterar os valores das variáveis:
    char file_teste[100] = "nome_arquivo_entrada.txt" 
    char file_new[100] = "nome_arquivo_saida.txt"

* Para todos os códigos começados em "quicksort", os testes com os arqui-
vos "teste_oc.txt", "teste_poc.txt", "teste_od.txt" e "teste_pod.txt" não
processam o teste 11, com 256 mil palavras, então é necessário alterar as
iterações para fazer apenas os 10 testes iniciais.

#Lista de Códigos:

1  - filaPrioridades.c
2  - filaPrioridades.h
3  - heapsort.c
4  - heapsort_testes.c
5  - insertion.c
6  - insertion_testes.c
7  - mergesort.c
8  - mergesort_testes.c
9  - quicksort1.c
10 - quicksort1_testes.c
11 - quicksort2.c
12 - quicksort2_testes.c

#Compilando e Rodando:

heapsort.c & heapsort_testes:
    gcc -o heapsort -Wall heapsort.c filaPrioridades.c
    ./heapsort
    gcc -o heapsort_testes -Wall heapsort_testes.c filaPrioridades.c
    ./heapsort_testes

insertion.c & insertion_testes.c:
    make insertion.c 
    ./insertion
    make insertion_testes.c
    ./insertion_testes

mergesort.c & mergesort_teste.c:
    make mergesort
    ./mergesort 
    make mergesort_teste
    ./mergesort_teste

quicksort1.c & quicksort1_testes.c
    make quicksort1
    ./quicksort1
    make quicksort1_testes
    ./quicksort1_testes

quicksort2.c & quicksort2_testes.c
    make quicksort2
    ./quicksort2
    make quicksort2_testes
    ./quicksort2_testes


