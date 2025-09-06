#include <iostream>

struct no {
    short dado;
    no *conexoes[3];
};

typedef no *ptr;
int
main()
{
    ptr no1 = (ptr) malloc(sizeof(no));
    no1->dado = 1;

    ptr no4 = (ptr) malloc(sizeof(no));
    no4->dado = 2;
    no1->conexoes[1] = no4;

    ptr no5 = (ptr) malloc(sizeof(no));
    no5->dado = 5;
    no4->conexoes[0] = no5;

    printf("%d\n", (ptr) no1->conexoes[1]->conexoes[0]->dado);
    //ou
    ptr dado_no5 = (ptr) no1->conexoes[1]->conexoes[0]->dado;
    printf("%d\n", dado_no5);

    return 0;
}
