#ifndef CONTAINERS_STACK_H
#define CONTAINERS_STACK_H

namespace s21 {

template <class T>
class stack {
 public:
  stack() : root(nullptr) {}

 private:
  struct Node {
    T data;
    Node* next;
  };
  Node* root;
};
}  // namespace s21

#endif  // CONTAINERS_STACK_H
