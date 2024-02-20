#ifndef UNTITLED_VECTORCONSTITERATOR_H
#define UNTITLED_VECTORCONSTITERATOR_H

#include <iterator>

namespace s21 {
    template<class T>
    class VectorConstIterator {
    public:
        using value_type = T;
        using reference = const T&;
        using pointer = const T*;
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;

        VectorConstIterator(pointer ptr) : m_Ptr(ptr) {}

        reference operator*() const {
            return *m_Ptr;
        }

        pointer operator->() const {
            return m_Ptr;
        }

        VectorConstIterator& operator++() {
            ++m_Ptr;
            return *this;
        }

        VectorConstIterator operator++(int) {
            VectorConstIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        VectorConstIterator& operator--() {
            --m_Ptr;
            return *this;
        }

        VectorConstIterator operator--(int) {
            VectorConstIterator tmp = *this;
            --(*this);
            return tmp;
        }

        friend bool operator==(const VectorConstIterator& a, const VectorConstIterator& b) {
            return a.m_Ptr == b.m_Ptr;
        }

        friend bool operator!=(const VectorConstIterator& a, const VectorConstIterator& b) {
            return a != b;
        }

    private:
        pointer m_Ptr;
    };
} // namespace s21

#endif //UNTITLED_VECTORCONSTITERATOR_H
