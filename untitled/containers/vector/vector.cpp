#include "vector.h"

namespace s21 {

    template<class T>
    void vector<T>::ReAlloc(vector::size_type newCapacity) {
        auto* newBlock = new T[newCapacity];

        if(newCapacity < m_Size) {
            m_Size = newCapacity;
        }

        for (size_type i = 0; i < m_Size; ++i) {
            newBlock[i] = m_Data[i];
        }
        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }

    template<class T>
    vector<T>::vector() {
        ReAlloc(2);
    }

    template<class T>
    vector<T>::vector(size_type n) {
        ReAlloc(n);
    }

    template<class T>
    vector<T>::vector(std::initializer_list<value_type> const &items) {
        m_Size = items.size();
        m_Capacity = m_Size;
        m_Data = new value_type[m_Capacity];
        std::copy(items.begin(), items.end(), m_Data);
    }

    template<class T>
    void vector<T>::reserve(vector::size_type size) {
        if (size > m_Capacity) {
            ReAlloc(size);
        }
    }

    template<class T>
    typename vector<T>::size_type vector<T>::capacity() {
        return m_Capacity;
    }

    template<class T>
    void vector<T>::shrink_to_fit() {
        if (m_Size < m_Capacity) {
            ReAlloc(m_Size);
             m_Capacity = m_Size;
        }
    }

    template<class T>
    vector<T>::vector(const vector &v) {
        m_Size = v.m_Size;
        m_Capacity = v.m_Size;
        m_Data = new value_type[m_Capacity];
        std::copy(v.m_Data, v.m_Data + m_Size, m_Data);
    }

    template<class T>
    vector<T>::vector(vector &&v)  noexcept {
        m_Data = v.m_Data;
        m_Size = v.m_Size;
        m_Capacity = v.m_Capacity;

        v.m_Data = nullptr;
        v.m_Size = 0;
        v.m_Capacity = 0;
    }

    template<class T>
    vector<T>::~vector() {
        delete[] m_Data;
        m_Size = 0;
        m_Capacity = 0;
    }

    template<class T>
    vector<T> &vector<T>::operator=(vector<T> &&v)  noexcept {
        if (this != &v) {
            clear();
            delete[] m_Data;
            m_Data = v.m_Data;
            m_Size = v.m_Size;
            m_Capacity = v.m_Capacity;

            v.m_Data = nullptr;
            v.m_Size = 0;
            v.m_Capacity = 0;
        }
        return *this;
    }

    template<class T>
    typename vector<T>::reference vector<T>::at(vector::size_type pos) {
        if (pos >= m_Size) {
            throw std::out_of_range("Index out of range");
        }
        return m_Data[pos];
    }


    template<class T>
    void vector<T>::push_back(vector::const_reference value) {
        if (m_Size >= m_Capacity) {
            ReAlloc(m_Capacity + m_Capacity / 2);
        }
        m_Data[m_Size++] = value;
    }

    template<class T>
    void vector<T>::pop_back() {
        if (m_Size > 0) {
            --m_Size;
        }
    }

    template<class T>
    void vector<T>::swap(vector<T> &other) {
        std::swap(m_Data, other.m_Data);
        std::swap(m_Size, other.m_Size);
        std::swap(m_Capacity, other.m_Capacity);
    }

    template<class T>
    typename vector<T>::size_type vector<T>::size() {
        return m_Size;
    }

    template<class T>
    typename vector<T>::reference vector<T>::operator[](vector::size_type pos) {
        if (m_Size <= pos) {
            throw std::out_of_range("Index out of range");
        }
        return m_Data[pos];
    }

    template<class T>
    typename vector<T>::const_reference vector<T>::operator[](vector::size_type pos) const {
        if (m_Size <= pos) {
            throw std::out_of_range("Index out of range");
        }
        return m_Data[pos];
    }

    template<class T>
    typename vector<T>::const_reference vector<T>::front() const {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        return m_Data[0];
    }

    template<class T>
    T* vector<T>::data() {
        return m_Data;
    }

    template<class T>
    typename vector<T>::const_reference vector<T>::back() const {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        return m_Data[m_Size - 1];
    }


    template<class T>
    void vector<T>::resize(vector::size_type sz) {
        if (sz == m_Size) {
            return;
        }
        if (sz < m_Size) {
            m_Size = sz;
        } else if (sz > m_Size) {
            if (sz > m_Capacity) {
                ReAlloc(sz);
            }
            for (size_type i = m_Size; i < sz; ++i) {
                m_Data[i] = value_type();
            }
            m_Size = sz;
        }
    }

    template<class T>
    void vector<T>::resize(vector::size_type sz, const vector::value_type &c) {
        if (sz == m_Size) {
            return;
        }
        if (sz < m_Size) {
            m_Size = sz;
        } else if (sz > m_Size) {
            if (sz > m_Capacity) {
                ReAlloc(sz);
            }
            for (size_type i = m_Size; i < sz; ++i) {
                m_Data[i] = c();
            }
            m_Size = sz;
        }
    }

    template<class T>
    bool vector<T>::empty() {
        return m_Size == 0;
    }

    template<class T>
    void vector<T>::clear() {
        while (!empty()) {
            pop_back();
        }
    }
}