#include "array.h"

namespace s21 {

    template<class T, std::size_t SIZE>
    array<T, SIZE>::array() : m_Size(SIZE) {}

    template<class T, std::size_t SIZE>
    array<T, SIZE>::array(std::initializer_list<value_type> const &items) {
        std::copy(items.begin(), items.end(), m_Data);
    }

    template <typename T, std::size_t SIZE>
    array<T, SIZE>::array(const array<T, SIZE> &a) {
        std::copy(a.m_Data, a.m_Data + SIZE, m_Data);
    }

    template <typename T, std::size_t SIZE>
    array<T, SIZE>::array(array<T, SIZE> &&a) noexcept {
        std::move(a.m_Data, a.m_Data + SIZE, m_Data);
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
    typename array<T, SIZE>::reference array<T, SIZE>::at(array::size_type pos) {
        return (*this)[pos];
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::const_reference array<T, SIZE>::at(array::size_type pos) const {
        return (*this)[pos];
    }

    template<class T, std::size_t SIZE>
    bool array<T, SIZE>::empty() {
        return !m_Size;
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::size_type array<T, SIZE>::size() {
        return m_Size;
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::size_type array<T, SIZE>::max_size() {
        return size();
    }

    template<class T, std::size_t SIZE>
    void array<T, SIZE>::swap(array <T, SIZE> &a) {
        std::swap_ranges(m_Data, m_Data + SIZE, a.m_Data);
    }

    template<class T, std::size_t SIZE>
    void array<T, SIZE>::fill(array::const_reference value) {
        std::fill(m_Data, m_Data + SIZE, value);
    }

    template<class T, std::size_t SIZE>
    array<T, SIZE> &array<T, SIZE>::operator=(const array<T, SIZE> &a) {
        for (size_t i = 0; i < SIZE; ++i) {
            m_Data[i] = a.m_Data[i];
        }
        return *this;
    }

    template<class T, std::size_t SIZE>
    array<T, SIZE> &array<T, SIZE>::operator=(array<T, SIZE> &&a) noexcept {
        for (size_type i = 0; i < SIZE; ++i) {
            m_Data[i] = std::move(a.m_Data[i]);
        }
        return *this;
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::reference array<T, SIZE>::operator[](array::size_type pos) {
        if (pos >= SIZE) {
            throw std::out_of_range("OutOfRangeError: Index out of array range");
        }
        return m_Data[pos];
    }

    template<class T, std::size_t SIZE>
    typename array<T, SIZE>::const_reference array<T, SIZE>::operator[](array::size_type pos) const {
        if (pos >= SIZE) {
            throw std::out_of_range("OutOfRangeError: Index out of array range");
        }
        return m_Data[pos];
    }

} // namespace s21
