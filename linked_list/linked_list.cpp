#include <iostream>

struct linked_list {
	char *string;
	struct linked_list *prox;
};

typedef struct linked_list item;

void
remove_item(item* head, int index)
{
    item *actual = head;

    int i = 0;

    while ((i < (index - 1)) and (actual->prox != NULL)){
        actual = actual->prox;
        i++;
    }

    if (actual->prox == NULL){
        return;
    }

    item *tb_removed = actual->prox;

    actual->prox = tb_removed->prox;

    free(tb_removed);
}

void
add_item(item* head, int index, char* value)
{
    item *novo = (item*) (malloc(sizeof(item)));

    novo->string = value;

    item *actual = head;

    int i = 1;

    while ((i<index) and (actual->prox != NULL)){
        actual = actual->prox;
        i++;
    }

    novo->prox = actual->prox;
    actual->prox = novo;
}

void
print_list(item* head)
{
    item *actual = head->prox;

    int i = 1;

    while (actual != NULL){
        printf("Item: %d -- Value: %s\n", i, actual->string);
        actual = actual->prox;
        i++;
    }
}

int
main()
{
    item *head = (item*) (malloc(sizeof(item)));
    head->prox = NULL;

    char *name_1 = "joao";
    char *name_2 = "gabriel";
    char *name_3 = "gutemberg";
    char *name_4 = "ramon";

    add_item(head, 1, name_1);
    add_item(head, 2, name_2);
    add_item(head, 3, name_3);
    add_item(head, 4, name_4); 

    print_list(head);

    remove_item(head, 2);
    //char *name_extra = "celio";
    //add_item(head, 2, name_extra);

    print_list(head);

	return 0;
}
