#include "iostream"
#include "stack.h"

int main(int argc, char const *argv[])
{
    Stack<int> s;
    s.push(15);
    s.push(24);
    s.push(18);
    s.push(19);
    s.push(20);

    s.dump();
    cout << "length: " << s.length()
        << ", capacity:" << s.getSize()
        << ", containts(24)=" << s.contains(24) << endl;

    s.pop();
    s.dump();
    cout << "length: " << s.length()
        << ", capacity:" << s.getSize()
        << ", containts(24)=" << s.contains(24) << endl;
    s.push(18);
    s.push(18);
    s.push(18);
    s.push(18);
    s.dump();
    cout << "length: " << s.length()
        << ", capacity:" << s.getSize()
        << ", containts(24)=" << s.contains(24) << endl;
    /*--------------
    OUTPUT
    i: 0 val: 15
    i: 1 val: 24
    i: 2 val: 18
    i: 3 val: 19
    i: 4 val: 20
    i: 5 val: 0
    length: 5, capacity:6, containts(24)=1
    --------------
    i: 0 val: 15
    i: 1 val: 24
    i: 2 val: 18
    i: 3 val: 19
    i: 4 val: 0
    i: 5 val: 0
    length: 4, capacity:6, containts(24)=1*/
    return 0;
}

