#ifndef LAB7_STACK_H
#define LAB7_STACK_H
#include <iostream>
using namespace std;
#include <stdexcept>
template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data{value}, next{nullptr} {}
    };
    Node* top;
    size_t size;

public:
    Stack():top{nullptr} {}
    ~Stack() {
        while (!isEmpty()) {
            Pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    T Peek() {
        if (isEmpty()) {
            cerr << "Stack is empty" << endl;
            exit(1);
        }
        return top->data;
    }

    T Pop() {
        if (isEmpty()) {
            cerr << "Stack is empty" << endl;
            exit(1);
        }
        T data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return data;
    }

    void Push(const T& element) {
        Node* newNode = new Node(element);
        newNode->next = top;
        top = newNode;
        size++;
    }

};

#endif //LAB7_STACK_H
