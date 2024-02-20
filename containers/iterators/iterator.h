//#ifndef CONTAINERS_ITERATOR_H
//#define CONTAINERS_ITERATOR_H
//
//#include "../containers/list/list.h"
//#include "../containers/node/ListNode.h"
//
//namespace s21 {
//template <typename T>
//class ListIterator {
//  friend class list<T>;
//  friend class ListConstIterator<T>;
//  using pointer = ListNode<T>*;
//
// public:
//  ListIterator() {}
//
//  ListIterator(const ListIterator& other) { operator=(other); }
//
//  ListIterator& operator=(const ListIterator& other) {
//    node_ = other.node_;
//    SetContainerPointers();
//    return *this;
//  }
//
//  ListIterator& operator++() {
//    if (next_ != nullptr) {
//      node_ = next_;
//      SetContainerPointers();
//    }
//    return *this;
//  }
//
//  ListIterator& operator--() {
//    if (next_ == nullptr) {
//      SetContainerPointers();
//    }
//    if (prev_ != nullptr) {
//      node_ = prev_;
//      SetContainerPointers();
//    }
//    return *this;
//  }
//  T& operator*() { return node_->value_; }
//  T* operator->() { return &(node_->value_); }
//  friend bool operator==(ListIterator& left_, ListIterator& right_) {
//    return left_.node_ == right_.node_;
//  }
//  friend bool operator!=(ListIterator& left_, ListIterator& right_) {
//    return !(left_.node_ == right_.node_);
//  }
//
// protected:
//  explicit ListIterator(const pointer node) : node_(node) {
//    SetContainerPointers();
//  }
//
//  void SetContainerPointers() {
//    if (node_ != nullptr) {
//      prev_ = node_->prev_;
//      next_ = node_->next_;
//    }
//  }
//  pointer node_ = nullptr;
//  pointer prev_ = nullptr;
//  pointer next_ = nullptr;
//};
//}  // namespace s21
//
//#endif  // CONTAINERS_ITERATOR_H
