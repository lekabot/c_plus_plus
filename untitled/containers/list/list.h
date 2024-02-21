#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

//#include <list>
#include <cstdio>
#include <initializer_list>
#include <limits>
#include "../node/node.h"
#include "../iterators/ListIterator.h"
#include "../iterators/ListConstIterator.h"

namespace s21 {
    template <class T>
    class list {
    public:
        friend class ListIterator<T>;
        friend class ListConstIterator<T>;

        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = ListIterator<T>;
        using const_iterator = ListConstIterator<T>;
        using size_type = size_t;

        list() : head(nullptr), tails(nullptr), list_size(0) {}

        list(size_type n) : list() {
            if (n > 0) {
                for (size_type i = 0; i < n; ++i) {
                    push_front(value_type());
                }
            }
        }

        list(std::initializer_list<value_type> const &items) : list() {
            for (const auto& item : items) {push_back(item);}
        }

        list(const list &other) : list() {
            for (auto it = other.begin(); it != other.end(); ++it) {
              push_back(*it);
          }
        };

        list(list &&other) noexcept : head(other.head), tails(other.tails), list_size(other.list_size) {
            other.head = nullptr;
            other.tails = nullptr;
            other.list_size = 0;
        }

        ~list() = default;

        list<T>& operator=(const list<T>& other) {
            if (this != &other) {
                clear();
                for (auto it = other.begin(); it != other.end(); ++it) {
                      push_back(*it);
                 }
            }
            return *this;
        }

        list<T>& operator=(list<T>&& other) noexcept {
            if (this != &other) {
                clear();
                head = other.head;
                tails = other.tails;
                list_size = other.list_size;

                other.head = nullptr;
                other.tails = nullptr;
                other.list_size = 0;
            }
            return *this;
        }


        const_reference front() const { return head->data; }
        const_reference back() const { return tails->data; }

        iterator begin() { return iterator(head); }
        iterator end() { return iterator(nullptr); }
        const_iterator begin() const { return const_iterator(head); }
        const_iterator end() const { return const_iterator(nullptr); }

        bool empty() const { return list_size == 0; }
        size_type size() const { return list_size; }
        size_type max_size() const { return std::numeric_limits<size_type>::max(); }

        void clear() {
            while (list_size) {
                pop_back();
            }
        }

        iterator insert(iterator pos, const_reference value) {
            auto new_node = new Node<T>(value);
            if (pos == end()) {
                if (empty()) {
                    head = tails = new_node;
                } else {
                    tails->next = new_node;
                    new_node->prev = tails;
                    tails = new_node;
                }
            } else {
                auto current = pos.current;
                if (current == head) {
                    new_node->next = head;
                    head->prev = new_node;
                    head = new_node;
                } else {
                    auto prev_node = current->prev;
                    prev_node->next = new_node;
                    new_node->prev = prev_node;
                    new_node->next = current;
                    current->prev = new_node;
                }
            }
            ++list_size;
            return iterator(new_node);
        }

        void erase(iterator pos) {
            if (pos == end() || empty()) { return; }
            if (pos == begin()) { pop_front(); }
            if (pos == iterator(tails)) { pop_back(); }
            else {
                auto node_to_remove = pos.current;
                auto prev_node = node_to_remove->prev;
                auto next_node = node_to_remove->next;
                prev_node->next = next_node;
                next_node->prev = prev_node;
                delete node_to_remove;
                --list_size;
            }
        }

        void push_back(const_reference value) {
            auto new_node = new Node<value_type>(value);
            if (!head) {
                head = tails = new_node;
            } else {
                tails->next = new_node;
                new_node->prev = tails;
                tails = new_node;
            }
            ++list_size;
        }
        void pop_back() {
            if (list_size == 0) {
                return;
            }
            if (list_size == 1) {
                delete tails;
                head = tails = nullptr;
            } else {
                Node<value_type> *prev = tails->prev;
                prev->next = nullptr;
                delete tails;
                tails = prev;
            }
            --list_size;
        }

        void push_front(const_reference value) {
            auto new_node = new Node<value_type>(value);
            if (head == nullptr) {
                head = tails = new_node;
            } else {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
            ++list_size;
        }

        void pop_front() {
            if (list_size == 0) {
                return;
            }
            if (list_size == 1) {
                delete head;
                head = tails = nullptr;
            } else {
                Node<value_type> *next_head = head->next;
                next_head->prev = nullptr;
                delete head;
                head = next_head;
            }
            --list_size;
        }

        void swap(list &other) {
            std::swap(head, other.head);
            std::swap(tails, other.tails);
            std::swap(list_size, other.list_size);
        }
        void merge(list &other) {
            iterator it1 = begin();
            iterator it2 = other.begin();
            iterator end1 = end();
            iterator end2 = end();

            while (it1 != end1 && it2 != end2) {
                if (*it2 < *it1) {
                    insert(it1, *it2);
                    ++it2;
                } else {
                    ++it1;
                }
            }
            while (it2 != end2) {
                push_back(*it2);
                ++it2;
            }
            other.clear();
        }

        void splice(const_iterator pos, list &other) {
            if (other.empty()) {
                return;
            }
            if (this == &other) { return; }
            auto splice_start = other.head;
            auto splice_end = other.tails;
            auto splice_size = other.size();

            other.head = other.tails = nullptr;
            other.list_size = 0;

            Node<T> *insert_before = pos.current;

            if (insert_before == nullptr) {
                if (empty()) {
                    head = splice_start;
                } else {
                    tails->next = splice_start;
                    splice_start->prev = tails;
                }
                tails = splice_end;
            } else {
                auto insert_after = insert_before->prev;
                if (insert_after == nullptr) {
                    head = splice_start;
                } else {
                    insert_after->next = splice_start;
                    splice_start->prev = insert_after;
                }
                splice_end->next = insert_before;
                insert_before->prev = splice_end;
            }
            list_size += splice_size;
        }

        void reverse() {
            if (list_size <= 1) {
                return;
            }
            auto *current = head;
            Node<value_type> *prevNode = nullptr;
            Node<value_type> *nextNode = nullptr;

            while (current != nullptr) {
                nextNode = current->next;
                current->next = prevNode;
                current->prev = nextNode;
                prevNode = current;
                current = nextNode;
            }

            tails = head;
            head = prevNode;
        }
        void unique() {
            if (head == nullptr || head->next == nullptr) {
                return;
            }
            auto current = head;
            while (current->next != nullptr) {
                if (current->data == current->next->data) {
                    auto duplicate = current->next;
                    current->next = current->next->next;
                    delete duplicate;
                    list_size--;
                } else {
                    current = current->next;
                }
            }
        }
//        void sort();

    private:
        Node<value_type> *head, *tails;
        size_type list_size;
    };
} // namespace s21

#include "list.tpp"

#endif //UNTITLED_LIST_H

