#include <iostream>

using namespace std;

class E2 {
    public:
        E2 () {
            next = this;
            prev = this;
        }
        int key;
        E2* next;
        E2* prev;
};

// q beszúrása r elé
void precede(E2* q, E2* r) {
    E2* p = r->prev;
    q->prev = p;
    q->next = r;
    r->prev = q;
    p->next = r->prev;
}

// q beszúrása p után
void follow(E2* p, E2* q) {
    E2* r = p->next;
    q->prev = p;
    q->next = r;
    r->prev = q;
    p->next = r;
}

// q kifűzése
void unlink(E2* q) {
    E2* p = q->prev;
    E2* r = q->next;
    p->next = r;
    r->prev = p;
    q->next = q;
    q->prev = q->next;
}

void write(E2 l) {
    E2 *p = l.next;
    while (p != &l) {
        cout << p->key << " ";
        p = p->next;
    }
    cout << endl;
}