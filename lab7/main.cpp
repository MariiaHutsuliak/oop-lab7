#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "Queue.h"
#include "OutputRestrictedQueue.h"
#include "Stack.h"
using namespace std;
int main() {
    /*
    try{
    SinglyLinkedList<int> list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    cout << "List after adding elements at the beginning:" << endl;
    cout << list << endl;

    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "List after adding elements at the end:" << endl;
    cout << list << endl;

    list.removeFront();
    list.removeBack();

    cout << "List after removing elements from front and back:" << endl;
    cout << list << endl;

    int searchValue = 20;
    if (list.search(searchValue)) {
        cout << searchValue << " is found in the list." << endl;
    } else {
        cout << searchValue << " is not found in the list." << endl;
    }

    size_t index = 1;
    int insertValue = 25;
    list.insertAtIndex(index, insertValue);

    cout << "List after inserting element at index " << index << ":" << endl;
    cout << list << endl;

    size_t removeIndex = 2;
    list.removeAtIndex(removeIndex);

    cout << "List after removing element at index " << removeIndex << ":" << endl;

    cout << list << endl;
     } catch (const exception &e) {
        cerr << "Exception: " << e.what() << endl;
    }
    try {
    DoublyLinkedList<int> list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "List data:" << endl;
    cout << list << endl;

    list.removeFront();
    list.removeBack();

    cout << "List data after removing front and back elements:" << endl;
    cout << list << endl;

    int searchValue = 20;
    if (list.search(searchValue)) {
        cout << searchValue << " is found in the list." << endl;
    } else {
        cout << searchValue << " is not found in the list." << endl;
    }

    list.insertAtIndex(1, 25);

    cout << "List data after inserting element at index 1:" << endl;
    cout << list << endl;

    list.removeAtIndex(2);

    cout << "List data after removing element at index 2:" << endl;
    cout << list << endl;
        } catch (const exception &e) {
        cerr << "Exception: " << e.what() << endl;
    } */


    Queue<int> queue(5);
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    cout << "Front element: " << queue.Peek() << endl;
    cout << "Dequeue: " << queue.Dequeue() << endl;
    cout << "Front element after dequeue: " << queue.Peek() << endl;

    Stack<string> stack;
    stack.Push("Hello");
    stack.Push("World");
    cout << "Top element: " << stack.Peek() << endl;
    cout << "Pop: " << stack.Pop() << endl;
    cout << "Top element after pop: " << stack.Peek() << endl;

    OutputRestrictedQueue<string> q;
    q.enqueueFront("apple");
    q.enqueueRear("banana");
    q.enqueueRear("orange");
    cout << "Dequeued from front: " << q.dequeueFront() << endl;
    q.enqueueFront("grape");
    while (!q.isEmpty()) {
        cout << "Dequeued from front: " << q.dequeueFront() << endl;
    }
    return 0;
}
