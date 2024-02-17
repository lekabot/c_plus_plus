#ifndef S21_LIST_H
#define S21_LIST_H

#include <list>

#include "../node/double_linked_list_node.h"

namespace s21 {
template <class T>
class list {
 public:
  list() : head(nullptr), tails(nullptr){};
  list(const list<T>& other);
  list(list<T>&& other) noexcept;
  list(std::initializer_list<T> init);

  ~list();

  T& operator[](size_t index);

  size_t size() const;
  bool empty() const;

  void push_front(const T& value);
  void push_back(const T& value);
  void pop_front();
  void pop_back();
  void clear();

  class iterator;
  iterator begin();
  iterator end();

 private:
  node<T>*head, *tails;
  size_t list_size;
};

template <typename T>
class list<T>::iterator {
 public:
  iterator(node<T>* ptr) : current(ptr) {}
  T& operator*() const { return current->data; }
  iterator& operator++() {
    current = current->next;
    return *this;
  }
  iterator& operator--() {
    current = current->prev;
    return *this;
  }
  bool operator==(const iterator& other) const {
    return current == other.current;
  }
  bool operator!=(const iterator& other) const { return !(*this == other); }

 private:
  node<T>* current;
};
};  // namespace s21

#endif  // S21_LIST_H
