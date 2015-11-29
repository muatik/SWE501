template <class T>
class Stack
{
private:
    unsigned int sp;
    unsigned int size;
    T* data;
public:
    Stack();
    ~Stack();
    virtual void dump();
    virtual void push(T value);
    virtual T pop();
    virtual bool contains(T value);
    virtual void empty();
    virtual bool isEmpty();
    virtual bool isFull();
    virtual unsigned int length();
    virtual unsigned int getSize();
    virtual void resize(unsigned int newSize);
};