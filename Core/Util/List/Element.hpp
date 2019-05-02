#ifndef ELEMENT_HPP_INCLUDED
#define ELEMENT_HPP_INCLUDED

#include <iostream>

template <class T>
class Element {
private:
    T *t;
    Element<T> *next;
    Element<T> *previous;
public:
    Element() {
        next = NULL;
        previous = NULL;
    }

    ~Element() {
        next = NULL;
        previous = NULL;
    }

    void setT(T *t_) {
        t = t_;
    }

    T *getT() {
        return t;
    }

    Element<T> *getNext() {
        return next;
    }

    void setNext(Element<T> *next_) {
        next = next_;
        next->setPrevious(this);
    }

    Element<T> *getPrevious() {
        return previous;
    }

    void setPrevious(Element<T> *previous_) {
        previous = previous_;
    }
};

#endif // ELEMENT_HPP_INCLUDED
