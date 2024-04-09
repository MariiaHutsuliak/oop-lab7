#ifndef LAB7_SINGLYLINKEDLIST_H
#define LAB7_SINGLYLINKEDLIST_H
#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;
template <typename T>
class SinglyLinkedList{
private:
    struct Node {
        T data;
        unique_ptr<Node> next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    unique_ptr<Node> head;
    size_t size;

public:
    SinglyLinkedList() : head(nullptr), size(0) {}

    void checkIndex(size_t index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
    }
    void insertAtBeginning(const T& value){
        unique_ptr<Node> newNode = make_unique<Node>(value);
        newNode->next = std::move(head);
        head = std::move(newNode);
        size++;
    }

    void insertAtEnd(const T& value){
        unique_ptr<Node> newNode = make_unique<Node>(value);
        Node *current = head.get();
        if (!current) {
            head = std::move(newNode);
            size++;
            return;
        }
        while (current->next) {
            current = current->next.get();
        }
        current->next = std::move(newNode);
        size++;
    }

    void removeFront(){
        if (!head){
            throw out_of_range("List is empty");
        }
        head = std::move(head->next);
        --size;
    }

    void removeBack(){
        if (!head){
            throw out_of_range("List is empty");
        }
        if (size == 1) {
            head.reset();
            --size;
            return;
        }
        Node *current = head.get();
        while (current->next->next) {
            current = current->next.get();
        }
        current->next.reset();
        --size;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        Node *current = head.get();
        for (size_t i = 0; i < index; ++i) {
            current = current->next.get();
        }
        return current->data;
    }

    [[nodiscard]] size_t getSize() const {
        return size;
    }

    [[nodiscard]] bool isEmpty() const {
        return size == 0;
    }

    bool search(const T& value) const {
        Node *current = head.get();
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next.get();
        }
        return false;
    }

    friend ostream &operator<<(ostream &os, const SinglyLinkedList<T> &obj) {
        Node *current = obj.head.get();
        os << "List data: " << endl;
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next.get();
        }
        os << endl;
        return os;
    }

    void insertAtIndex(size_t index, const T& value){
        checkIndex(index);
        if (index == 0) {
            insertAtBeginning(value);
            return;
        } else if (index == size) {
            insertAtEnd(value);
            return;
        } else {
            unique_ptr<Node> newNode = make_unique<Node>(value);
            Node *current = head.get();
            for (size_t i = 0; i < index - 1; i++) {
                current = current->next.get();
            }
            newNode->next = std::move(current->next);
            current->next = std::move(newNode);
            size++;
        }

    }

    void removeAtIndex(size_t index) {
        checkIndex(index);
        if (index == 0) {
            removeFront();
            return;
        } else if (index == size - 1) {
            removeBack();
            return;
        }

        Node *current = head.get();
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next.get();
        }
        current->next = std::move(current->next->next);
        --size;

    }
};



#endif //LAB7_SINGLYLINKEDLIST_H
