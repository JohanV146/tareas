#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "node.hpp"

class queue {
private:
    node *head;
    node *tail;
public:
    queue () {
        head = nullptr;
        tail = nullptr;
    }

    void enqueue (char c) {
        node *n = new node (c);
        if (tail == nullptr) {
            head = n;
        } else {
            tail->setNextV (n);
        }

        tail = n;
    }

    char dequeue () {
        if (head != nullptr) {
            node *t = head;
            head = head->getNextV ();
            if (empty ())
                tail = nullptr;
            return t->getName ();
        } else return '\0';
    }

    bool empty () {
        return head == nullptr;
    }
};

#endif