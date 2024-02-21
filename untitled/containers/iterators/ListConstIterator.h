#ifndef UNTITLED_LISTCONSTITERATOR_H
#define UNTITLED_LISTCONSTITERATOR_H

#include <iterator>
#include "../node/node.h"
#include "ListIterator.h"

namespace s21 {
    template<class T>
    class ListConstIterator : public ListIterator<T> {
    public:
        ListConstIterator() : ListIterator<T>() {}
        explicit ListConstIterator(const ListIterator<T> &node_) : ListIterator<T>(node_) {}
        typename ListIterator<T>::const_reference operator*() const {
            return ListIterator<T>::operator*();
        }
    };
}

#endif //UNTITLED_LISTCONSTITERATOR_H
