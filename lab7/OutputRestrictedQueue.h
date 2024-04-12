#ifndef LAB7_OUTPUTRESTRICTEDQUEUE_H
#define LAB7_OUTPUTRESTRICTEDQUEUE_H
#include <iostream>
using namespace std;
template <typename T>
class OutputRestrictedQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& data) : data{data}, next{nullptr}, prev{nullptr} {}
    };
    Node* front;
    Node* rear;

public:
    OutputRestrictedQueue() : front(nullptr), rear(nullptr) {}

    ~OutputRestrictedQueue() {
        while (!isEmpty()) {
            dequeueFront();
        }
    }

    void enqueueFront(const T& element) {
        Node* newNode = new Node(element);
        cout << "Inserting to front: " << element << endl;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void enqueueRear(const T& element) {
        Node* newNode = new Node(element);
        cout << "Inserting to rear: " << element << endl;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    T dequeueFront() {
        if (isEmpty()) {
            cerr << "Queue is empty" << endl;
            exit(1);
        }
        T element = front->data;
        Node* temp = front;
        cout << "Deleting: " << element << endl;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        return element;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};
#endif //LAB7_OUTPUTRESTRICTEDQUEUE_H
