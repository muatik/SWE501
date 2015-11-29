template<typename T>
class Queue
{
private:
    unsigned int size;
    unsigned int capacity;
    void resize(unsigned int newCapacity);

    T* list;
    int head;
    int tail;
public:
    Queue();
    Queue(unsigned int capacity);
    ~Queue();
    virtual void enqueue(T item);
    virtual T dequeue();
    virtual bool isEmpty();
    virtual bool isFull();
    virtual unsigned int count();
    virtual void display();
};