#ifndef CONTAINERS_SET_H
#define CONTAINERS_SET_H

#include "../tree/tree.h"

namespace s21 {
    template<class Key>
    class set : public tree<Key, Key>{
    public:
        using key_type = Key;
        using value_type = Key;
        using reference = value_type &;
        using const_reference = const Key &;
        using iterator = typename tree<Key, Key>::Iterator;
        using const_iterator = typename tree<Key, Key>::ConstIterator;
        using size_type = size_t;

        set() : tree<Key, Key>(){};
        set(std::initializer_list<value_type> const &items);
        set(const set &other) : tree<Key, Key>(other){};
        set(set &&other) noexcept : tree<Key, Key>(std::move(other)){};
        set &operator=(set &&other) noexcept;
        set &operator=(const set &other);
        ~set() = default;

        iterator find(const Key &key) { return tree<Key, Key>::find(key); };
    };
} // namespace s21
#include "set.tpp"
#endif //CONTAINERS_SET_H