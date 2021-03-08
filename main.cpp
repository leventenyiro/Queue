#include <iostream>
#include "E2.h"

using namespace std;

int main(int argc, char const *argv[])
{
    E2 l = E2();
    
    E2 e1 = E2();
    e1.key = 5;
    follow(&l, &e1);
    
    /*E2 *e2();
    e2->key = 3;
    follow(e1, e2);*/

    //write(l);
    cout << l.next->next->key << endl;
    
    return 0;
}
