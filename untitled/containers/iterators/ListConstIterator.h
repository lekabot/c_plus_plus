#ifndef UNTITLED_LISTCONSTITERATOR_H
#define UNTITLED_LISTCONSTITERATOR_H

#include <iterator>
#include "../node/node.h"

namespace s21 {
    template<class T>
    class ListConstIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;
        
        explicit ListConstIterator(Node<T>* node) : current(node) {}

        reference operator*() const { return current->data; }
        pointer  operator->() const { return &(current->data); }
        ListConstIterator& operator++() { current = current->next; return *this; }
        ListConstIterator operator++(int) { ListConstIterator temp = *this; ++(*this); return temp; }
        ListConstIterator& operator--() { current = current->prev; return *this; }
        ListConstIterator operator--(int) { ListConstIterator temp = *this; --(*this); return temp; }
        bool operator==(const ListConstIterator& other) const { return current == other.current; }
        bool operator!=(const ListConstIterator& other) const { return *this != other; }
    private:
        Node<T>* current;
    };
}

#endif //UNTITLED_LISTCONSTITERATOR_H
