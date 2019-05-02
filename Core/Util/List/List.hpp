#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include "Element.hpp"

template <class T>
class List {
private:
    Element<T> *head;
    Element<T> *tail;
    int elementCount;
public:
    List() : elementCount(0) {
        head = new Element<T>();
        tail = new Element<T>();
        head->setNext(tail);
    }

    void addElement(T *t) {
        Element<T> *previous = tail->getPrevious();
        Element<T> *newElement = new Element<T>();
        newElement->setT(t);
        previous->setNext(newElement);
        newElement->setNext(tail);
        elementCount++;
    }

    void removeAt(int index) {
        if (index >= elementCount) {
            throw "ArrayIndexOutOfBoundsException";
        }
        Element<T> *toRemove = getContainerAt(index);
        Element<T> *previous = toRemove->getPrevious();
        previous->setNext(toRemove->getNext());
        delete toRemove;
        elementCount--;
    }

    T *getElementAt(int index) {
        return getContainerAt(index)->getT();

    }

    int getElementCount() {
        return elementCount;
    }
private:
    Element<T> *getContainerAt(int index) {
        if (index >= elementCount || index < 0) {
            throw "ArrayIndexOutOfBoundsException";
        }
        Element<T> *element = head;
        for (int i = 0; i <= index; i++) {
            element = element->getNext();
            if (element == NULL) {
                // assertion?
                throw "IllegalStateException";
            }
        }
        return element;
    }
};

#endif // LIST_HPP_INCLUDED
