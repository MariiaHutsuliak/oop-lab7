#ifndef LAB7_QUEUE_H
#define LAB7_QUEUE_H
#include <iostream>
using namespace std;
template <typename T>
class Queue {
private:
   T* array;
   int capacity;
   int size;
   int front;
   int rear;

public:
    Queue(int capacity) : capacity{capacity}, front{0}, rear{-1}, size{0} {
        array = new T[capacity];
    }
    ~Queue() {
        delete[] array;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void Enqueue(const T& element) {
        if (isFull()) {
            cerr << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = element;
        size++;
    }

    T Dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty" << endl;
            exit(1);
        }
        T item = array[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    T Peek() {
        if (isEmpty()) {
            cerr << "Queue is empty" << endl;
            exit(1);
        }
        return array[front];
    }

};


#endif //LAB7_QUEUE_H
