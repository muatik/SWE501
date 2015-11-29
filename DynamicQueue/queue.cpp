#include "iostream"
#include "queue.h"
#include <stdexcept>
using namespace std;


template<typename T>
Queue<T>::Queue() {
    capacity = 10;
    resize(capacity);
}

template<typename T>
Queue<T>::~Queue() {
    delete[] list;
}


template<typename T>
Queue<T>::Queue(unsigned int capacity) {
    this->capacity = capacity;
    resize(capacity);
}

template<typename T>
void Queue<T>::enqueue(T item) {
    if (isFull())
        resize(capacity * 1.5);
        // throw overflow_error("queue is full");
    tail = (tail + 1) % capacity;
    cout << "enqueue tail: " << tail << endl;
    list[tail] = item;
    size++;
};

template<typename T>
T Queue<T>::dequeue() {
    if (isEmpty())
        throw underflow_error("queue is empty.");
    T item = list[head];
    head = (head + 1) % capacity;
    size--;
    if ((capacity / 3) > size)
        resize(size * 1.5);
    return item;
}

template<typename T>
unsigned int Queue<T>::count(){
    return size;
};


template<typename T>
bool Queue<T>::isEmpty(){
    return size == 0;
};


template<typename T>
bool Queue<T>::isFull(){
    return size == capacity;
};

template<typename T>
void Queue<T>::resize(unsigned int newCapacity){
    cout << "resizing " << newCapacity << endl;
    T* newList = new T[newCapacity]();
    tail = size - 1;
    head = 0;
    for (int i = 0; i < size; ++i)
    {
        newList[i] = list[(i + head) % newCapacity];
    }
    delete[] list;
    list = newList;
    this->capacity = newCapacity;
    display();
};
template<typename T>
void Queue<T>::display() {
    cout << "displaying... head: " << head << " tail: " << tail << " size: " << size << endl;
    for (int i = 0; i < size; ++i)
    {
        int location = ((i + head) % capacity);
        cout << location << ". val: " << list[location] << endl;
        /* code */
    }
};

