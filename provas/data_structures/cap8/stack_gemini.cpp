#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Error: Stack underflow" << std::endl;
            return -1;
        }
        Node* temp = top;
        int popped = temp->data;
        top = top->next;
        delete temp;
        return popped;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Error: Stack is empty" << std::endl;
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element is: " << stack.peek() << std::endl;

    stack.pop();

    std::cout << "Top element is: " << stack.peek() << std::endl;

    return 0;
}