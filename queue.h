#pragma once

#include <iostream>
#include "e2.h"

using namespace std;

class Queue {
    private:
        E2 *last;

    public:
        Queue() {
            last = new E2();
        }

        void add(int x) {
            E2* q = new E2();
            q->key = x;
            follow(last, q);
        }

        int rem() {
            if (last->prev != last) {
                int x = last->prev->key;
                unlink(last->prev);
                return x;
            }
            // emptyQueueError
            return 0;
        }

        int first() {
            if (last->prev != last) {
                return last->prev->key;
            }
            // emptyQueueError
            return 0;
        }

        int length() {
            int db = 0;
            E2 *p = last->next;
            while (p != last) {
                db++;
                p = p->next;
            }
            return db;
        }

        bool isEmpty() {
            return length() == 0;
        }

        void setEmpty() {
            E2 *p = last->next;
            while (p != last) {
                E2 *temp = p;
                p = p->next;
                unlink(temp);
                delete(temp);
            }
        }

        ~Queue() {
            E2 *p = last->next;
            while (p != last) {
                E2 *temp = p;
                p = p->next;
                unlink(temp);
                delete(temp);
            }
            delete(p);
        }

        friend std::ostream &operator<<(std::ostream &os, Queue &q);
};

ostream &operator<<(std::ostream& os, Queue &q) {
    os << "Elements: ";
    E2 *p = q.last->next;
    while (p != q.last) {
        os << p->key << " ";
        p = p->next;
    }
    return os;
}