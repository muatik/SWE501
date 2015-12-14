#include "sortedLinkedList.h"
#include "iostream"

using namespace std;


SortedLinkedList::SortedLinkedList(){
    head = NULL;
}

void SortedLinkedList::insert(int value){
    if (head == NULL || head->value >= value) {
        head = new Node(value, head);
        return;
    }

    Node* i = head;
    while (i->next != NULL && value > i->next->value) {
        i = i->next;
    }

    Node* newNode = new Node(value, i->next);
    i->next = newNode;
}

bool SortedLinkedList::retreiveItem(int value){
    Node* i = head;
    while (i != NULL) {
        if (i->value == value)
            return true;
        i = i->next;
    }
    return false;
}

void SortedLinkedList::deleteItem(int value){
    if(retreiveItem(value)){
        Node* current = head;
        if(current->value == value){
            head = current->next;
        } else {
            while(current->next->value != value) {
                current = current->next;
            }
            current->next = current->next->next;
      }
    }
}

SortedLinkedList::~SortedLinkedList(){

}

void SortedLinkedList::display(){
    cout << "----- displaying -----" << endl;
    Node* i = head;
    while (i != NULL) {
        cout << i->value << endl;
        i = i->next;
    }
}

