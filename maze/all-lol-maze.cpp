#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

struct node {
    char* name;
    node* left;
    node* down;
    node* up;
    node* right;
    bool visited;
};

class track {
   private:
    char move;

    track* child[4];
    track* prev;

    node* final = NULL;

   public:
    void set_child(track* potential, int index) { child[index] = potential; };
    void set_move(char choice) { move = choice; }

    void set_final(node* final_node) { final = final_node; }

    node* get_final() { return final; }

    track* roll_back() { return prev; }
    // int shortest_path(){}
};

void search(char* name_to_find, node* start, track* head) {
    node* actual = start;
    unsigned short int i = 0;

    if (actual->name != NULL) {
        if (strcmp(actual->name, name_to_find)) {
            head->set_final(actual);
        }
    }

    actual->visited = true;

    if (actual->left != NULL && actual->left->visited != true) {
        track* potential = (track*)(malloc(sizeof(track)));
        potential->set_move('l');
        head->set_child(potential, i);
        i++;

        search(name_to_find, actual->left, potential);
    }

    if (actual->down != NULL && actual->down->visited != true) {
        track* potential = (track*)(malloc(sizeof(track)));
        potential->set_move('d');
        head->set_child(potential, i);
        i++;

        search(name_to_find, actual->down, potential);
    }

    if (actual->up != NULL && actual->up->visited != true) {
        track* potential = (track*)(malloc(sizeof(track)));
        potential->set_move('u');
        head->set_child(potential, i);
        i++;

        search(name_to_find, actual->up, potential);
    }

    if (actual->right != NULL && actual->right->visited != true) {
        track* potential = (track*)(malloc(sizeof(track)));
        potential->set_move('r');
        head->set_child(potential, i);
        i++;

        search(name_to_find, actual->right, potential);
    }
}

void insert_name(node* head, char* string, int size) {
    head->name = (char*)(malloc(sizeof(size + 1)));
    strcpy(head->name, string);
}

int main() {
    node* inicio = (node*)(malloc(sizeof(node)));

    node* bisecao = (node*)(malloc(sizeof(node)));
    inicio->right = bisecao;

    node* moedas = (node*)(malloc(sizeof(node)));
    bisecao->up = moedas;
    bisecao->left = inicio;
    insert_name(moedas, "moedas", 6);

    node* vazio = (node*)(malloc(sizeof(node)));
    bisecao->down = vazio;
    moedas->down = vazio;
    vazio->up = moedas;

    node* boss = (node*)(malloc(sizeof(node)));
    boss->up = moedas;
    boss->down = vazio;
    vazio->right = boss;
    moedas->right = boss;
    insert_name(boss, "boss", 4);

    node* fim = (node*)(malloc(sizeof(node)));
    fim->left = boss;
    boss->left = fim;
    insert_name(fim, "game over", 9);

    node* resultado = (node*)(malloc(sizeof(node)));
    insert_name(resultado, " ", 9);

    track* path = (track*)(malloc(sizeof(track)));
    search("game over", inicio, path);

    return 0;
}
