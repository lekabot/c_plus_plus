#ifndef S21_LIST_H
#define S21_LIST_H

#include "../node/ListNode.h"

namespace s21 {
    template<class T>
    class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

  list() : head(nullptr), tails(nullptr), list_size(0) {}
  list(size_type n) : list() {}
  list(std::initializer_list<value_type> const &items) : list() {}
  list(const list &other) = default;
  list(list &&other) noexcept = default;
  ~list() = default;

  const_reference front() const { return head->data; }
  const_reference back() const { return tails->data; }

  iterator begin() { return iterator(head); }
  iterator end() { return iterator(nullptr); }
  const_iterator begin() const { return const_iterator(head); }
  const_iterator end() const { return const_iterator(nullptr); }

  bool empty() const { return list_size == 0; }
  size_type size() const { return list_size; }
  size_type max_size() const { return std::numeric_limits<size_type>::max(); }

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

 private:
  node<T> *head, *tails;
  size_t list_size;
    };
} // namespace s21

#endif