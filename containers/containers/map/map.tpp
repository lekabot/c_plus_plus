namespace s21 {

template <class Key, class T>
typename map<Key, T>::iterator map<Key, T>::begin() {
  return map<Key, T>::MapIterator(tree<Key, T>::getMin(tree<Key, T>::m_Root));
}

template <class Key, class T>
typename map<Key, T>::iterator map<Key, T>::end() {
  if (tree<Key, T>::m_Root == nullptr) return begin();
  auto last_node = tree<Key, T>::getMax(tree<Key, T>::m_Root);
  MapIterator _s(nullptr, last_node);
  return _s;
}

template <class Key, class T>
map<Key, T>::map(const std::initializer_list<value_type> &items) {
  for (auto i = items.begin(); i != items.end(); ++i) {
    insert(*i);
  }
}

template <class Key, class T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const map::value_type &value) {
  return insert(value.first, value.second);
}

template <class Key, class T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key &key, const T &obj) {
  std::pair<iterator, bool> return_value;
  if (tree<Key, T>::m_Root == nullptr) {
    tree<Key, T>::m_Root = new typename tree<Key, T>::TreeNode(key, obj);
    return_value.first = iterator(tree<Key, T>::m_Root);
    return_value.second = true;
  } else {
    bool inserted =
        tree<Key, T>::recursiveInsert(tree<Key, T>::m_Root, key, obj);
    return_value.first = find(key);
    return_value.second = inserted;
  }
  return return_value;
}

template <class Key, class T>
typename map<Key, T>::iterator map<Key, T>::find(const Key &key) {
  auto node = tree<Key, T>::binarySearch(tree<Key, T>::m_Root, key);
  return iterator(node);
}

template <class Key, class T>
T &map<Key, T>::MapIterator::return_value() {
  if (tree<Key, T>::Iterator::m_Iter_Node == nullptr) {
    static T fake_value{};
    return fake_value;
  }
  return tree<Key, T>::Iterator::m_Iter_Node->m_Value;
}

template <class Key, class T>
map<Key, T> &map<Key, T>::operator=(map &&other) noexcept {
  if (this != &other) {
    tree<Key, T>::operator=(std::move(other));
  }
  return *this;
}

template <class Key, class T>
map<Key, T> &map<Key, T>::operator=(const map &other) {
  if (this != &other) {
    tree<Key, T>::operator=(other);
  }
  return *this;
}
template <class Key, class T>
T &map<Key, T>::operator[](const Key &key) {
  auto it = find(key);
  if (it == nullptr) {
    std::pair<typename map<Key, T>::iterator, bool> pr =
        insert(std::make_pair(key, T()));
    it = pr.first;
  }
  return it.return_value();
}

template <class Key, class T>
T &map<Key, T>::at(const Key &key) {
  auto it = find(key);
  if (it == nullptr) {
    throw std::out_of_range("Key no found");
  }
  return it.return_value();
}

template <class Key, class T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key &key, const T &obj) {
  auto el = find(key);
  if (el != this->end()) {
    erase(el);
    std::pair<typename map<Key, T>::iterator, bool> pr = insert(key, obj);
    pr.second = false;
    return pr;
  }
  return insert(key, obj);
}

template <class Key, class T>
void map<Key, T>::erase(map::iterator pos) {
  if (tree<Key, T>::m_Root == nullptr || pos.m_Iter_Node == nullptr) return;
  tree<Key, T>::m_Root =
      tree<Key, T>::recursiveDelete(tree<Key, T>::m_Root, (*pos).first);
}

template <class Key, class T>
void map<Key, T>::merge(map<Key, T> &other) {
  map m_Tree(other);
  auto it = m_Tree.begin();
  for (; it != m_Tree.end(); ++it) {
    auto key = (*it).first;
    auto obj = (*it).second;
    std::pair<iterator, bool> pr = insert(key, obj);
    if (pr.second) other.erase(pr.first);
  }
}

template <typename Key, typename T>
template <class... Args>
std::vector<std::pair<typename map<Key, T>::iterator, bool>>
map<Key, T>::insert_many(Args &&...args) {
  std::vector<std::pair<typename map<Key, T>::iterator, bool>> vec;
  for (const auto &arg : {args...}) {
    vec.push_back(insert(arg));
  }
  return vec;
}

}  // namespace s21