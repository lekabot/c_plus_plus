#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

#include <cstdio>
#include <initializer_list>
#include <limits>
#include "node.h"

namespace s21 {
    template <class T>
    class list {
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = ListIterator<T>;
        using const_iterator = ListConstIterator<T>;
        using size_type = size_t;
    public:
        list() : head(nullptr), tails(nullptr), list_size(0) {}
        explicit list(size_type n) : list() {}
        list(std::initializer_list<value_type> const &items) : list() {}
        list(const list &other) = default;
        list(list &&other) noexcept = default;
        ~list() = default;

        const_reference front() const { return head->data; }
        const_reference back() const { return tails->data; }

//        iterator begin() { return iterator(head); }
//        iterator end() { return iterator(nullptr); }
//        const_iterator begin() const { return const_iterator(head); }
//        const_iterator end() const { return const_iterator(nullptr); }

        [[nodiscard]] bool empty() const { return list_size == 0; }
        [[nodiscard]] size_type size() const { return list_size; }
        [[nodiscard]] size_type max_size() const { return std::numeric_limits<size_type>::max(); }

        void clear();
//        iterator insert(iterator pos, const_reference value);
//        void erase(iterator pos);
        void push_back(const_reference value);
        void pop_back();
        void push_front(const_reference value);
        void pop_front();
        void swap(list &other);
//        void merge(list &other);
//        void splice(const_iterator pos, list &other);
        void reverse();
        void unique();
//        void sort();

    private:
        Node<value_type> *head, *tails;
        size_type list_size;
    };
}

#endif //UNTITLED_LIST_H
