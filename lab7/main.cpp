#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;
int main() {
    SinglyLinkedList<int> list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    cout << "List after adding elements at the beginning:" << endl;
    list.display();

    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "List after adding elements at the end:" << endl;
    list.display();

    list.removeFront();
    list.removeBack();

    cout << "List after removing elements from front and back:" << endl;
    list.display();

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
    list.display();

    size_t removeIndex = 2;
    list.removeAtIndex(removeIndex);

    cout << "List after removing element at index " << removeIndex << ":" << endl;

    list.display();
    return 0;
}
