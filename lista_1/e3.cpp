#include <iostream>

struct no {
    short dado;

    no *esquerda;
    no *meio;
    no *direita;
};

typedef no *ptr;

int
main()
{
    //alocando espaco pro no1
    ptr no1 = (ptr) malloc(sizeof(no));
    no1->dado = 1;

    //alocando espaco pro no4
    ptr no4 = (ptr) malloc(sizeof(no));
    no4->dado = 2;
    no1->meio = no4;

    //alocando espaco pro no5
    ptr no5 = (ptr) malloc(sizeof(no));
    no5->dado = 5;
    no4->esquerda = no5;

    ptr ptr_no5 = no1->meio->esquerda;

    //testando
    printf("%d\n", (ptr) no1->meio->esquerda->dado);
    //ou
    printf("%d\n", ptr_no5->dado);

    return 0;
}
