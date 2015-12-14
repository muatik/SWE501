#include "sortedLinkedList.cpp"
#include "iostream"
#include "ctime"
#include "cstdlib"

using namespace std;

int main() {
    SortedLinkedList a;
    int count = 50;

    srand(time(0));
    for (int i = 0; i < count; ++i)
    {
        a.insert(rand() % 100);
    }

    int c = rand() % 100;
    if (a.retreiveItem(c)) {
        cout << "random number " << c << " is found in the list" << endl;
    } else {
        cout << "random number " << c << " is not found in the list" << endl;
    }

    a.display();
}