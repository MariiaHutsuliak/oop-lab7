#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
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
    } */
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

    list.removeAtIndex(23456);

    cout << "List data after removing element at index 2:" << endl;
    cout << list << endl;
        } catch (const exception &e) {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
