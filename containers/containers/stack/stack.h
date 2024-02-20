// #ifndef CONTAINERS_STACK_H
// #define CONTAINERS_STACK_H
//
// namespace s21 {
//
// template <class T>
// class stack {
//  public:
//   using value_type = T;
//   using reference = T &;
//   using const_reference = const T &;
//   using size_type = size_t;
//
//   stack() : top(nullptr) {}
//   stack(std::initializer_list<value_type> const &items);
//   stack(const stack &s);
//   stack(stack &&s);
//   ~stack();
//   operator=(stack && s);
//
//   const_reference top();
//
//   bool empty();
//   size_type size();
//
//   void push(const_reference value);
//   void pop();
//   void swap(stack &other);
//
//  private:
// };
// }  // namespace s21
//
// #endif  // CONTAINERS_STACK_H
