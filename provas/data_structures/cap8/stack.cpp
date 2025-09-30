#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

struct linked_list{
  char *data;
  linked_list *next;
};

typedef linked_list* node;

class stack{
  private:
    node top; 

  public:
    stack() {top = nullptr;}

    void
    push(char* value)
    {
      node tb_added = (node) (malloc(sizeof(linked_list)));
      tb_added->data = value;
      tb_added->next = top;
      top = tb_added;
    }

    int
    pop(char* value)
    {
      if (top == nullptr) return -1;

      node tb_removed = top;
      strcpy(value, top->data);

      top = top->next;

      free(tb_removed);

      return 0;
    }

    int
    peek(char* value)
    {
      if (top == nullptr) return -1;

      strcpy(value, top->data);
      return 0;
    }
};

int
main()
{
  stack pilha;
  pilha.push("joao");
  pilha.push("celio");
  pilha.push("araujo");
  pilha.push("sander");
  pilha.push("de");
  
  char* string = (char*) (malloc(64));

  pilha.peek(string);

  cout << "ANTES DE REMOVER: " << string << endl;

  pilha.pop(string);

  cout << "DADO REMOVIDO: " << string << endl;
  
  pilha.peek(string);

  cout << "DEPOIS DE REMOVER: " << string << endl;

  free(string);
  return 0;
}
