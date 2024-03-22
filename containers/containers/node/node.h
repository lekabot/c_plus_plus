#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

namespace s21 {
template <class T>
struct Node {
  T data;
  Node* prev;
  Node* next;
  Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};
}  // namespace s21

#endif  // UNTITLED_NODE_H
