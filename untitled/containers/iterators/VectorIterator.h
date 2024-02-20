#ifndef UNTITLED_VECTORITERATOR_H
#define UNTITLED_VECTORITERATOR_H

#include <iterator>

namespace s21 {
    template <class T>
    class VectorIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit VectorIterator(pointer ptr) : m_Ptr(ptr) {};

        reference operator*() const {
            return *m_Ptr;
        }

        pointer operator->() {
            return m_Ptr;
        }

        VectorIterator& operator++() {
            ++m_Ptr;
            return *this;
        }

        VectorIterator operator++(int) {
            VectorIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        VectorIterator& operator--() {
            --m_Ptr;
            return *this;
        }

        VectorIterator operator--(int) {
            VectorIterator tmp = *this;
            --(*this);
            return tmp;
        }

        friend bool operator==(const VectorIterator& a, const VectorIterator& b) {
            return a.m_Ptr == b.m_Ptr;
        }

        friend bool operator!=(const VectorIterator& a, const VectorIterator& b) {
            return a != b;
        }

            private:
        pointer m_Ptr;

    };
} // namespace s21

#endif //UNTITLED_VECTORITERATOR_H
