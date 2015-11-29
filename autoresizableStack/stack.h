#include "iostream"
#include "stdexcept"
#include "stack_def.h"

using namespace std;

template<class T>
Stack<T>::Stack() {
    data = new T[1];
    this->empty();
}

template<class T>
void Stack<T>::empty() {
    delete[] data;
    data = NULL;
    size = 3;
    data = new T[size]();
    sp = 0;
}

template<class T>
Stack<T>::~Stack() {
    delete[] data;
}

template<class T>
void Stack<T>::push(T value) {
    if (this->isFull())
        this->resize(size * 1.5);
        // throw std::overflow_error("stack overflow");
    data[sp++] = value;
}

template<class T>
T Stack<T>::pop() {
    if (!this->isEmpty()) {
        T d = data[--sp];
        data[sp] = 0;
        if (size / 3 > sp)
            this->resize(size / 3);
        return d;
    }
    throw std::overflow_error("stack underflow");
}

template<class T>
bool Stack<T>::contains(T value) {
    for (int i = 0; i < sp; ++i)
        if (data[i] == value)
            return
             true;
    return false;
}

template<class T>
bool Stack<T>::isEmpty() {
    return sp == 0;
}

template<class T>
bool Stack<T>::isFull() {
    return sp == size;
}

template<class T>
unsigned int Stack<T>::length() {
    return sp;
}

template<class T>
unsigned int Stack<T>::getSize() {
    return size;
}

template<class T>
void Stack<T>::resize(unsigned int newSize) {

    T* newData = new T[newSize]();

    for (int i = 0; i < sp; ++i)
        newData[i] = data[i];
    size = newSize;
    delete[] data;
    data = NULL;
    data = newData;
}
template<class T>
void Stack<T>::dump() {
    cout << "--------------\n";
    for (int i = 0; i < size; ++i)
    {
        cout << "i: " << i << " val: " << data[i] << endl;
    }
}

