#ifndef CONTAINERS_ARRAY_H
#define CONTAINERS_ARRAY_H

#include <algorithm>
#include <cstddef>

namespace s21 {
template <class T, std::size_t SIZE>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a) noexcept;
  ~array() = default;

  iterator begin();
  iterator end();
  const_iterator cbegin(void) const;
  const_iterator cend(void) const;

  reference at(size_type pos);
  const_reference at(size_type pos) const;

  reference front();
  reference back();
  const_reference front() const;
  const_reference back() const;

  bool empty();
  size_type size();
  size_type max_size();

  void swap(array &a);
  void fill(const_reference value);

  array &operator=(const array &a);
  array &operator=(array &&a) noexcept;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;

 private:
  size_type m_Size = SIZE;
  value_type m_Data[SIZE] = {};
};
}  // namespace s21
#include "array.tpp"
#endif  // CONTAINERS_ARRAY_H
