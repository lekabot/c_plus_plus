#ifndef CONTAINERS_NODE_H
#define CONTAINERS_NODE_H

#include <iostream>

namespace s21 {
template <typename T>
struct node {
  node(const T& it) : item(it), next(nullptr), prev(nullptr) {}
  T item;
  node<T>* next;
  node<T>* prev;
};
};  // namespace s21

#endif  // CONTAINERS_NODE_H
