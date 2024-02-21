#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H

#include <algorithm>
#include <cstdio>
#include <initializer_list>

namespace s21 {
    template <class T>
    class vector {
    public:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = T*;
        using const_iterator = const T *;
        using size_type = size_t;

        vector();
        explicit vector(size_type n);
        vector(std::initializer_list<value_type> const &items);
        vector(const vector &v);
        vector(vector &&v) noexcept;
        ~vector();
        vector<T>& operator=(vector &&v) noexcept;

        reference at(size_type pos);
        const_reference operator[](size_type pos) const;
        reference operator[](size_type pos);
        const_reference front() const;
        const_reference back() const;
        T* data();

        iterator begin() {return iterator(&m_Data[0]); }
        iterator end() {return iterator(&m_Data[m_Size]); }
        const_iterator cbegin() const noexcept { return m_Data; }
        const_iterator cend() const noexcept { return m_Data + m_Size; }

        bool empty() const;
        size_type size() const;
        size_type max_size() const {return std::numeric_limits<size_type>::max();}
        void reserve(size_type size);
        size_type capacity() const;
        void shrink_to_fit();


        void clear();
        iterator insert(iterator pos, const_reference value);
        void erase(iterator pos);
        void push_back(const_reference value);
        void pop_back();
        void swap(vector& other);
        void resize(size_type sz);
        void resize(size_type sz, const value_type& c);

    private:
        void ReAlloc(size_type newCapacity);
    private:
        value_type* m_Data = nullptr;
        size_type m_Size = 0;
        size_type m_Capacity = 0;
    };
}
#include "vector.tpp"

#endif //UNTITLED_VECTOR_H
