#ifndef CONTAINERS_NODE_H
#define CONTAINERS_NODE_H

#include <iostream>

namespace s21 {
template <typename T>
struct ListNode {
  T value_ = T();
  ListNode* previous_ = nullptr;
  ListNode* next_ = nullptr;
  explicit ListNode(T value = T(), ListNode* previous = nullptr,
                    ListNode* next = nullptr)
      : value_(value), previous_(previous), next_(next) {}
};
};  // namespace s21

#endif  // CONTAINERS_NODE_H
