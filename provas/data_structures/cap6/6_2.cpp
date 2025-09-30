#include <cstdlib>
#include <iostream>
using namespace std;

struct linked_list {
  char *name;
  linked_list *next;
};

typedef struct linked_list* node;

void
traverse_print(node head)
{
  node actual = head->next;

  while (actual != NULL)
  {
    cout << actual -> name << endl;
    actual = actual -> next;
  }
}

int
main()
{
  node head = (node) (malloc(sizeof(node)));

  node node1 = (node) (malloc(sizeof(node)));
  node1->name = "JOAO";
  head->next = node1;

  node node2 = (node) (malloc(sizeof(node)));
  node2->name = "CELIO";
  node1->next = node2; 

  node node3 = (node) (malloc(sizeof(node)));
  node3->name = "DE";
  node2->next = node3;

  node node4 = (node) (malloc(sizeof(node)));
  node4->name = "ARAUJO";
  node3->next = node4;

  node node5 = (node) (malloc(sizeof(node)));
  node5->name = "SANDER";
  node4->next = node5;

  traverse_print(head);

  return 0;
}
