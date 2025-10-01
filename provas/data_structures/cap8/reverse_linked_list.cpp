#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

struct linked_list {
    char* data;
    linked_list* next;
};

typedef struct linked_list* node;

class stack {
   private:
    node top;

   public:
    stack() { top = nullptr; }

    void push(char* value) {
        node tb_added = (node)(malloc(sizeof(linked_list)));
        tb_added->data = value;
        tb_added->next = top;
        top = tb_added;
    }

    int pop(char** value) {
        if (top == nullptr) return -1;

        node tb_removed = top;
        *value = top->data;

        top = top->next;

        free(tb_removed);

        return 0;
    }

    int peek(char** value) {
        if (top == nullptr) return -1;

        *value = top->data;
        return 0;
    }
};

void revert_linked_list(node head) {
    stack s;

    node actual = head->next;

    while (actual != NULL) {
        s.push(actual->data);
        actual = actual->next;
    }

    actual = head->next;

    while (actual != NULL) {
        s.pop(&actual->data);
        actual = actual->next;
    }
}

void print_list(node head) {
    node actual = head->next;

    if (actual == NULL) {
        cout << "The list is empty.\n" << endl;
        return;
    }

    int i = 1;

    while (actual != NULL) {
        printf("Item: %d -- Value: %s\n", i, actual->data);
        actual = actual->next;
        i++;
    }
    cout << endl;  // For better spacing
}

int main() {
    node head = (node)(malloc(sizeof(linked_list)));
    head->next = NULL;

    node node1 = (node)(malloc(sizeof(linked_list)));
    node1->data = "JOAO";
    head->next = node1;

    node node2 = (node)(malloc(sizeof(linked_list)));
    node2->data = "CELIO";
    node1->next = node2;

    node node3 = (node)(malloc(sizeof(linked_list)));
    node3->data = "DE";
    node2->next = node3;

    node node4 = (node)(malloc(sizeof(linked_list)));
    node4->data = "ARAUJO";
    node3->next = node4;

    node node5 = (node)(malloc(sizeof(linked_list)));
    node5->data = "SANDER";
    node4->next = node5;
    node5->next = NULL;

    print_list(head);

    revert_linked_list(head);

    print_list(head);

    return 0;
}
