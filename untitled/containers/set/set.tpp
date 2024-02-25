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
} // namespace s21