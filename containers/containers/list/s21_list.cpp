#include "s21_list.h"

namespace s21 {

template <typename T>
void list<T>::push_front(const T& value) {
    auto tmp = new node<T>(value);
    if
    tmp.prev = head;
    head->next = tmp;
    tmp.next = nullptr;
    list_size++;
}

template <typename T>
void list<T>::push_back(const T& value) {
    auto tmp = new node<T>(value);
    tmp.prev = tails;
    tails->next = tmp;
    tmp->next = nullptr;
    list_size++;
}

template <typename T>
void list<T>::pop_front() {
    head->prev = nullptr;
    head->next = nullptr;
    delete head;
    list_size--;
}

template <typename T>
void list<T>::pop_back() {
    tails->prev = nullptr;
    tails->next = nullptr;
    delete tails;
    list_size--;
}

template <typename T>
void list<T>::clear() {
    while (list_size != 0) {
        pop_back();
    }
}

template <typename T>
list<T>::~list() {
    clear();
}

template <typename T>
size_t list<T>::size() const {
    return list_size;
}

template <typename T>
bool list<T>::empty() const {
    return list_size == 0;
}

template <typename T>
list<T>::list(const list<T>& other) {

}

}  // namespace s21
