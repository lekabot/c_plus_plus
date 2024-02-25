#ifndef CONTAINERS_MAP_H
#define CONTAINERS_MAP_H

#include "../tree/tree.h"

namespace s21 {
    template <class Key, class T>
    class map : public tree<Key, T> {
    public:
        class MapIterator;
        class MapConstIterator;

        using key_type = Key;
        using mapped_type = T;
        using value_type = std::pair<const key_type,mapped_type> ;
        using reference = value_type &;
        using const_reference = const value_type;
        using iterator = MapIterator;
        using const_iterator = MapConstIterator;
        using size_type = size_t;

        class MapIterator : public tree<Key, T>::Iterator {
            public:
            friend class map;
            MapIterator() : tree<Key, T>::Iterator() {}
            MapIterator(typename tree<Key, T>::TreeNode *node, typename tree<Key, T>::TreeNode *past_node = nullptr) :
                    tree<Key, T>::Iterator(node, past_node = nullptr) {};
            value_type &operator*();
            protected:
                T &return_value();
        };

        class MapConstIterator : public MapIterator {
        public:
            friend class map;
            MapConstIterator() : MapIterator() {}
            MapConstIterator(typename tree<Key, T>::TreeNode *node, typename tree<Key, T>::TreeNode *past_node = nullptr) :
                    tree<Key, T>::Iterator(node, past_node = nullptr) {};
            const_reference operator*() const { return MapIterator::operator*(); };
        };

        map() : tree<Key, T>(){};
        map(std::initializer_list<value_type> const &items);
        map(const map &m) : tree<Key, T>(m) {};
        map(map &&m) noexcept : tree<Key, T>(std::move(m)) {};
        ~map() = default;

        map &operator=(map &&other) noexcept;
        map &operator=(const map &other);

        T& at(const Key& key);
        T& operator[](const Key& key);

        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;

//        size_type size();
//        size_type max_size();

//        void clear();
        std::pair<iterator, bool> insert(const value_type& value);
        std::pair<iterator, bool> insert(const Key& key, const T& obj);
        std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
        void erase(iterator pos);
//        void swap(map& other);
        void merge(map& other);

//        bool contains(const Key& key);
    private:
        iterator find(const Key &key);
    };

} // namespace s21
#include "map.tpp"
#endif //CONTAINERS_MAP_H
