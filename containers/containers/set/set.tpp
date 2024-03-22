namespace s21 {

template <typename Key>
set<Key>::set(const std::initializer_list<value_type> &items) {
  for (auto i = items.begin(); i != items.end(); ++i) {
    tree<Key, Key>::insert(*i);
  }
}

template <typename Key>
set<Key> &set<Key>::operator=(set &&other) noexcept {
  if (this != &other) {
    tree<Key, Key>::operator=(std::move(other));
  }
  return *this;
}

template <typename Key>
set<Key> &set<Key>::operator=(const set &other) {
  if (this != &other) {
    tree<Key, Key>::operator=(other);
  }
  return *this;
}

template <class Key>
template <class... Args>
std::vector<std::pair<typename set<Key>::iterator, bool>> set<Key>::insert_many(
    Args &&...args) {
  std::vector<std::pair<typename set<Key>::iterator, bool>> vec;
  for (const auto &arg : {args...}) {
    vec.push_back(tree<Key, Key>::insert(arg));
  }
  return vec;
}

}  // namespace s21