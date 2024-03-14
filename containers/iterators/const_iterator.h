//#ifndef CONTAINERS_CONST_ITERATOR_H
//#define CONTAINERS_CONST_ITERATOR_H
//
//#include "../containers/list/list.h"
//#include "../containers/node/ListNode.h"
//#include "iterator.h"
//
//namespace s21 {
//template <typename T>
//class ListConstIterator {
//  friend class list<T>;
//  using pointer = ListNode<T>*;
//
// public:
//  ListConstIterator() {}
//  ListConstIterator(const ListConstIterator& other) { operator=(other); }
//  explicit ListConstIterator(const ListIterator<T>& item) : node_(item.node_) {
//    SetContainerPointers();
//  }
//
//  ListConstIterator& operator=(const ListConstIterator& other) {
//    node_ = other.node_;
//    SetContainerPointers();
//    return *this;
//  }
//
//  ListConstIterator& operator++() {
//    if (next_ != nullptr) {
//      node_ = next_;
//      SetContainerPointers();
//    }
//    return *this;
//  }
//
//  ListConstIterator& operator--() {
//    if (next_ == nullptr) {
//      SetContainerPointers();
//    }
//    if (prev_ != nullptr) {
//      node_ = prev_;
//      SetContainerPointers();
//    }
//    return *this;
//  }
//
//  const T& operator*() { return node_->value_; }
//  const T* operator*() { return &(node_->value_); }
//  friend bool operator==(const ListConstIterator& left_,
//                         const ListConstIterator& right_) {
//    return left_.node_ == right_.node_;
//  }
//  friend bool operator!=(const ListConstIterator& left_,
//                         const ListConstIterator& right_) {
//    return !(left_.node_ == right_.node_);
//  }
//
// protected:
//  explicit ListConstIterator(const pointer node) : node_(node) {
//    SetContainerPointers();
//  }
//
//  void SetContainerPointers() {
//    if (node_ != nullptr) {
//      prev_ = node_->prev_;
//      next_ = node_->next_;
//    }
//  }
//
//  pointer node_ = nullptr;
//  pointer prev_ = nullptr;
//  pointer next_ = nullptr;
//};
//}  // namespace s21
//#endif  // CONTAINERS_CONST_ITERATOR_H
