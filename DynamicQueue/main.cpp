#include <iostream>
#include "queue.cpp"

using namespace std;


int main(int argc, char const *argv[]) {
    Queue<int> q(3);
    q.enqueue(54);
    q.enqueue(8);
    q.enqueue(76);
    q.enqueue(14);
    q.enqueue(16);
    q.enqueue(8);

    q.dequeue();
    q.enqueue(22);
    q.dequeue();
    q.enqueue(41);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}