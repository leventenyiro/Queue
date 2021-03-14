#include <iostream>
#include "queue.h"
#include "E2.h"

using namespace std;

int main(int argc, char const *argv[]) {   
    Queue q = Queue();

    q.add(6);
    q.add(7);

    cout << q << endl;

    q.setEmpty();

    q.add(34);
    q.add(35);
    cout << q.length() << endl;

    cout << q.first() << endl;

    cout << q << endl;

    q.rem();

    cout << q << endl;

    q.setEmpty();

    cout << q.length() << endl;
    q.add(5);
    cout << q.length() << endl;

    q.~Queue();

    q.add(5);
    cout << q << endl;

    return 0;
}
