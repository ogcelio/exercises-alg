#include <iostream>
#include <string>
#include <limits>

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
        std::cout << "You can't remove an item that doesn't exist.\n" << std::endl;
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

    if (actual == NULL){
        std::cout << "The list is empty.\n" << std::endl;
        return;
    }

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
    char x; //choice
    int index;

    item *head = (item*) (malloc(sizeof(item)));
    head->prox = NULL;

    std::cout << "Hi, select one of the following keys:\n" << std::endl;

    while (true) {
        std::cout << "[P] Print || [I] Insert || [D] Delete || [E] Exit\n" << std::endl;

        std::cin >> x;

        if (x == 'p' or x == 'P'){
            print_list(head);
        }
        else if (x == 'i' or x == 'I'){
            // char *value = (char*) (malloc(sizeof(char) * 256));
            // std::string value;

            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Write the string to add in the linked list:\n" << std::endl;
            // std::cin >> value;
            // std::getline(std::cin, value);

            std::cout << "Now, write the index to insert the element:\n" << std::endl;
            std::cin >> index;

            add_item(head, index, value);
        }
        else if (x == 'd' or x == 'D'){
            std::cout << "Write the index of the item to delete:\n" << std::endl;
            std::cin >> index;

            remove_item(head, index);
        }
        else if (x == 'e' or x == 'E'){
            std::cout << "Exiting..." << std::endl;
            break;
        }
        else{
            std::cout << "Pick one of the options listed.\n" << std::endl;
        }
    }

    return 0;
}
