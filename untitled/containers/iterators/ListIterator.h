//#ifndef UNTITLED_LISTITERATOR_H
//#define UNTITLED_LISTITERATOR_H
//
//#include <iterator>
//#include "../node/node.h"
//
//namespace s21 {
//    template <class T>
//    class ListIterator {
//    public:
//        using iterator_category = std::forward_iterator_tag;
//        using value_type = T;
//        using difference_type = std::ptrdiff_t;
//        using pointer = T*;
//        using reference = T&;
//
//        explicit ListIterator(Node<T>* node) : current(node) {}
//
//        reference operator*() const { return current->data; }
//        pointer  operator->() const { return &(current->data); }
//        ListIterator& operator++() { current = current->next; return *this; }
//        ListIterator operator++(int) { ListIterator temp = *this; ++(*this); return temp; }
//        ListIterator& operator--() { current = current->prev; return *this; }
//        ListIterator operator--(int) { ListIterator temp = *this; --(*this); return temp; }
//        bool operator==(const ListIterator& other) const { return current == other.current; }
//        bool operator!=(const ListIterator& other) const { return *this != other; }
//    private:
//        Node<T>* current;
//    };
//};
//#endif //UNTITLED_LISTITERATOR_H
