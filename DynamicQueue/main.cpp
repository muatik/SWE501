#include <iostream>
#include "queue.cpp"
#include "string"

using namespace std;

struct Car {
    string id;
};

int main(int argc, char const *argv[]) {
    Car c1, c2, c3, c4, c5, c6;
    c1.id = "34c";
    c2.id = "52k";
    c3.id = "12j";
    c4.id = "44a";
    c5.id = "37y";
    c6.id = "93r";
    Queue<Car> ship(2);
    ship.enqueue(c1);
    ship.enqueue(c2);
    ship.enqueue(c3);
    ship.enqueue(c4);
    ship.dequeue();
    ship.dequeue();
    ship.enqueue(c5);
    ship.enqueue(c6);

    while (!ship.isEmpty()) {
        Car c = ship.dequeue();
        cout << c.id << " dequed" << endl;
    }
    return 0;
}