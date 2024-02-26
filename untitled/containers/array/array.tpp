#include "array.h"

namespace s21 {

    template<class T, std::size_t SIZE>
    array<T, SIZE>::array() : m_Size(SIZE) {}

    template<class T, std::size_t SIZE>
    array<T, SIZE>::array(std::initializer_list<value_type> const &items) {
//        for
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::reference array<T, SIZE>::front() {
        return m_Data[0];
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::reference array<T, SIZE>::back() {
        return m_Data[SIZE - 1];
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::const_reference array<T, SIZE>::front() const {
        return m_Data[0];
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::const_reference array<T, SIZE>::back() const {
        return m_Data[SIZE - 1];
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::iterator array<T, SIZE>::end() {
        return m_Data + m_Size;
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::iterator array<T, SIZE>::begin() {
        return m_Data;
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::const_iterator array<T, SIZE>::cbegin(void) const {
        return m_Data;
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::const_iterator array<T, SIZE>::cend(void) const {
        return m_Data + m_Size;
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::reference at(typename array<T, SIZE>::size_type pos) {
        return (*this)[pos];
    }


} // namespace s21
