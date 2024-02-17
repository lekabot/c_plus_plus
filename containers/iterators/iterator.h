#ifndef CONTAINERS_ITERATOR_H
#define CONTAINERS_ITERATOR_H

namespace s21 {
    template <class Container>
    class iterator {
    public:
        using value_type = typename Container::value_type;
        using pointer_type = value_type*;
        using reference_type = value_type&;

        iterator(pointer_type ptr) : m_Ptr(ptr) {};

        iterator& operator++() {
            m_Ptr++;
            return *this;
        }

        iterator operator++(int) {
            iterator p_Iter = *this;
            ++(*this);
            return p_Iter;
        }

        iterator& operator--() {
            m_Ptr--;
            return *this;
        }

        iterator operator--(int) {
            iterator p_Iter = *this;
            --(*this);
            return p_Iter;
        }

        reference_type operator[](int index) {
            return *(m_Ptr[index]);
        }

        pointer_type operator->() {
            return m_Ptr;
        }

        reference_type operator*() {
            return *m_Ptr;
        }

        bool operator==(const iterator& other) const {
            return m_Ptr == other.m_Ptr;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }

    private: 
        pointer_type m_Ptr;
    };
}

#endif //CONTAINERS_ITERATOR_H
