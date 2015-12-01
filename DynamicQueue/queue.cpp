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
    if (newCapacity == 0)
        newCapacity = 1;
    T* newList = new T[newCapacity]();
    for (int i = 0; i < size; ++i)
    {
        newList[i] = list[(i+head) % capacity];
    }
    tail = size - 1;
    head = 0;
    delete[] list;
    list = newList;
    this->capacity = newCapacity;
};

