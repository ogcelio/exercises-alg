#include <cstdlib>
#include <iostream>
using namespace std;

struct linked_list{
  char* name;
  linked_list *next;
};

typedef struct linked_list* no;

void
delete_from_front(no head)
{
  delete[] (head->name);
  delete[] (head);
}

int
main()
{
  no head = (no) (malloc(sizeof(no)));

  no no1 = (no) (malloc(sizeof(no)));
  head->next = no1;
  no1->name = "joao";
  
  delete_from_front(head);

  cout << no1 << endl;
  cout << head->name << endl;
  return 0;
}
