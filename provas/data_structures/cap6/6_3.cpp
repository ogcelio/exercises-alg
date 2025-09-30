void
add_item(item* head, int index, char* value)
{
    if (index <= 0) {
        std::cout << "Cannot insert at an invalid index. Please use an index of 1 or greater.\n" << std::endl;
        free(value); // Prevent memory leak if index is invalid
        return;
    }

    item *novo = (item*) (malloc(sizeof(item)));
    if (novo == NULL) {
        perror("Failed to allocate memory for new item");
        free(value); // Prevent memory leak on malloc failure
        return;
    }

    novo->string = value;

    item *actual = head;

    int i = 1;

    while ((i < index) && (actual->prox != NULL)){
        actual = actual->prox;
        i++;
    }

    novo->prox = actual->prox;
    actual->prox = novo;
}
