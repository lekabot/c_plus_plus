#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

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
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using size_type = size_t;

        class ListIterator {
            friend class s21::list<T>;
        public:
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;

            ListIterator() : current(nullptr) {}
            ListIterator(Node<T>* node) : current(node) {}
            ListIterator(const ListIterator& other) : current(other.current) {}
            ListIterator(Node<T>* node, Node<T>* last_node) : current(node), last(last_node) {}

            reference operator*() const { return current->data; }
            pointer operator->() const { return &(current->data); }
            ListIterator& operator++() { current = current->next; return *this; }
            ListIterator operator++(int) { ListIterator temp = *this; ++(*this); return temp; }
            ListIterator& operator--() {
                if (current) {
                    current = current->prev;
                } else {
                    current = last;
                }
                return *this;
            }
            ListIterator operator--(int) { ListIterator temp = *this; --(*this); return temp; }
            bool operator==(const ListIterator& other) const { return current == other.current; }
            bool operator!=(const ListIterator& other) const { return current != other.current; }
            bool operator<(const ListIterator& other) const { return current < other.current; }
            bool operator<=(const ListIterator& other) const { return current <= other.current; }
            bool operator>(const ListIterator& other) const { return current > other.current; }
            bool operator>=(const ListIterator& other) const { return current >= other.current; }

        protected:
            Node<T>* current;
            Node<T>* last;
        };

        class ListConstIterator : public ListIterator {
        public:
            ListConstIterator() : ListIterator() {}
            ListConstIterator(const ListIterator &node_) : ListIterator(node_) {}
            typename ListIterator::reference operator*() const {
                return ListIterator::operator*();
            }
        };

        using iterator = ListIterator;
        using const_iterator = ListConstIterator;

        list() : head(nullptr), tails(nullptr), list_size(0) {}

        list(size_type n) : list() {
            for (size_type i = 0; i < n; ++i) {
                push_front(value_type());
            }
        }

        list(std::initializer_list<value_type> const &items) : list() {
            for (const auto& item : items) {
                push_back(item);
            }
        }

        list(const list &other) : list() {
            for (auto it = other.begin(); it != other.end(); ++it) {
                push_back(*it);
            }
        }

        list(list &&other) noexcept : head(other.head), tails(other.tails), list_size(other.list_size) {
            other.head = nullptr;
            other.tails = nullptr;
            other.list_size = 0;
        }

        ~list() {
            clear();
        }

        list<T>& operator=(const list<T>& other) {
            if (this != &other) {
                while (!empty()) {
                    pop_front();
                }
                Node<value_type> *current = other.head;
                while (current) {
                    push_back(current->data);
                    current = current->next;
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

        iterator begin() const { return iterator(head); }
        iterator end() const { return ListIterator(tails->next, tails); }
        const_iterator cbegin() const { return const_iterator(head); }
        const_iterator cend() const { return const_iterator(nullptr); }

        bool empty() const { return list_size == 0; }
        size_type size() const { return list_size; }
        size_type max_size() const { return std::numeric_limits<size_type>::max(); }

        void clear() {
            while (!empty()) {
                pop_front();
            }
        }

        iterator insert(iterator pos, const_reference value) {
            if (pos == begin()) {
                push_front(value);
                pos = head;
            } else if (pos == end()) {
                push_back(value);
                pos = tails;
            } else {
                Node<T>* current = pos.current;
                Node<T>* blank = new Node(value);
                blank->next = current;
                blank->prev = current->prev;
                current->prev->next = blank;
                current->prev = blank;
                list_size++;
                return iterator(blank);
            }
            return pos;
        }

        void erase(iterator pos) {
            if (pos == end() || empty()) { return; }
            Node<T>* current = pos.current;
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tails = current->prev;
            }
            delete current;
            --list_size;
        }

        void push_back(const_reference value) {
            Node<T>* new_node = new Node<T>(value);
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
            if (empty()) { return; }
            Node<T>* temp = tails;
            if (tails->prev) {
                tails = tails->prev;
                tails->next = nullptr;
            } else {
                head = tails = nullptr;
            }
            delete temp;
            --list_size;
        }

        void push_front(const_reference value) {
            Node<T>* new_node = new Node<T>(value);
            if (!head) {
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
        void sort() {
            if (list_size <= 1) {
                return;
            }

            for (iterator it1 = begin(); it1 != end(); ++it1) {
                for (iterator it2 = it1; it2 != end(); ++it2) {
                    if (*it2 < *it1) {
                        std::swap(*it1, *it2);
                    }
                }
            }
        }


    private:
        Node<value_type> *head, *tails;
        size_type list_size;
    };
} // namespace s21

#include "list.tpp"

#endif //UNTITLED_LIST_H

