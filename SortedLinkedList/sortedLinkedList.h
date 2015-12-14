#ifndef SORTED_LINKEDLIST_H
#define SORTED_LINKEDLIST_H

struct Node
{
    Node*  next;
    int value;
    Node(int value, Node* next): value(value), next(next)
    {

    }
};

class SortedLinkedList
{
    private:
        Node * head;
    public:
        SortedLinkedList();
        ~SortedLinkedList();

        void insert(int value);
        bool retreiveItem(int value);
        void deleteItem(int value);

        void display();

};

#endif // SORTED_LINKEDLIST_H