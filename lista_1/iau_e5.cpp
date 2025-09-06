#include <iostream>

struct person {
    char *first_name;
    char *last_name;
};

typedef person p;

char
collect_name(char *array_person,
             int num_person,
             int num_name)
{
    /*
    num_person is the index of the person in the array_person.
    if num_name == 0, the first name will be collected;
    else if num_name == 1, the last name will be collected;
    */
    
    if (num_name == 0){
        char *name_return = (p) array_person[num_person]->last_name;
        return *name_return;
    }
    else if (num_name == 1){
        char *name_return = (p) array_person[num_person]->last_name;
        return *name_return;
    }
    else
        return 1;
}

int
main()
{
    p pessoa1 = (p) malloc(sizeof(person));
    strncpy(pessoa1->first_name, "joao");
    strncpy(pessoa1->last_name, "sander");

    p pessoa2 = (p) malloc(sizeof(person));
    strncpy(pessoa2->first_name, "luiz");
    strncpy(pessoa2->last_name, "otavio");

    p pessoa3 = (p) malloc(sizeof(person));
    strncpy(pessoa3->first_name, "leandro");
    strncpy(pessoa3->last_name, "oliveira");

    p pessoa4 = (p) malloc(sizeof(person));
    strncpy(pessoa4->first_name, "vitor");
    strncpy(pessoa4->last_name, "pinto");

    p pessoa5 = (p) malloc(sizeof(person));
    strncpy(pessoa5->first_name, "marcio");
    strncpy(pessoa5->last_name, "godinho");
    
    p *array_name[5] = {pessoa1, pessoa2, pessoa3, pessoa4, pessoa5};
    printf("%s\n", (p) collect_name(array_name, 3, 1));

    return 0;
}
