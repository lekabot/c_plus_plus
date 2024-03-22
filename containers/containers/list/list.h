#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

#include <cstdio>
#include <initializer_list>
#include <limits>

#include "../node/node.h"

namespace s21 {
template <class T>
class list {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  class ListIterator {
    friend class s21::list<T>;

   public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    ListIterator() : current(nullptr) {}
    ListIterator(Node<T>* node) : current(node) {}
    ListIterator(const ListIterator& other) : current(other.current) {}
    ListIterator(Node<T>* node, Node<T>* last_node)
        : current(node), last(last_node) {}
    ListIterator& operator=(const ListIterator& other) {
      if (this != &other) {
        current = other.current;
      }
      return *this;
    }

    reference operator*() const { return current->data; }
    pointer operator->() const { return &(current->data); }
    ListIterator& operator++() {
      current = current->next;
      return *this;
    }
    ListIterator operator++(int) {
      ListIterator temp = *this;
      ++(*this);
      return temp;
    }
    ListIterator& operator--() {
      if (current == nullptr) {
        current = last;
      } else {
        current = current->prev;
      }
      return *this;
    }
    ListIterator operator--(int) {
      ListIterator it = *this;
      current = current->prev;
      return it;
    }
    bool operator==(const ListIterator& other) const {
      return current == other.current;
    }
    bool operator!=(const ListIterator& other) const {
      return current != other.current;
    }
    bool operator<(const ListIterator& other) const {
      return current < other.current;
    }
    bool operator<=(const ListIterator& other) const {
      return current <= other.current;
    }
    bool operator>(const ListIterator& other) const {
      return current > other.current;
    }
    bool operator>=(const ListIterator& other) const {
      return current >= other.current;
    }

   protected:
    Node<T>* current;
    Node<T>* last;
  };

  class ListConstIterator : public ListIterator {
   public:
    ListConstIterator() : ListIterator() {}
    ListConstIterator(const ListIterator& node_) : ListIterator(node_) {}
    ListConstIterator(Node<T>* node, Node<T>* last_node)
        : ListIterator(node, last_node) {}
    typename ListIterator::reference operator*() const {
      return ListIterator::operator*();
    }
  };

  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

  list() : head(nullptr), tails(nullptr), list_size(0) {}

  list(size_type n) : list() {
    for (size_type i = 0; i < n; ++i) {
      push_front(value_type());
    }
  }

  list(std::initializer_list<value_type> const& items) : list() {
    for (const auto& item : items) {
      push_back(item);
    }
  }

  list(const list& other) : list() {
    for (auto it = other.cbegin(); it != other.cend(); ++it) {
      push_back(*it);
    }
  }

  list(list&& other) noexcept
      : head(other.head), tails(other.tails), list_size(other.list_size) {
    other.head = nullptr;
    other.tails = nullptr;
    other.list_size = 0;
  }

  ~list() { clear(); }

  list<T>& operator=(const list<T>& other);
  list<T>& operator=(list<T>&& other) noexcept;

  const_reference front() const { return head->data; }
  const_reference back() const { return tails->data; }

  iterator begin() { return iterator(head); }
  iterator end() { return head ? ListIterator(tails->next, tails) : begin(); }
  const_iterator cbegin() const { return const_iterator(head); }
  const_iterator cend() const { return const_iterator(tails->next, tails); }

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
  void swap(list& other);
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void reverse();
  void unique();
  void sort();

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args);

  template <typename... Args>
  void insert_many_back(Args&&... args);

  template <typename... Args>
  void insert_many_front(Args&&... args);

 private:
  Node<value_type>*head, *tails;
  size_type list_size;
};
}  // namespace s21

#include "list.tpp"

#endif  // UNTITLED_LIST_H
