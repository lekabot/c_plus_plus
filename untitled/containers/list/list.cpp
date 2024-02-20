#include "list.h"

namespace s21 {

    template <class T>
    list<T>& list<T>::operator=(list<T> &&l)  noexcept {
        if (l != nullptr) {
            clear();
            head = l.head;
            tails = l.tails;
            list_size = l.list_size;

            l.head = nullptr;
            l.tails = nullptr;
            l.list_size = 0;
        }
        return *this;
    }

    template<class T>
    void list<T>::clear() {
        while (list_size) {
            pop_back();
        }
    }

    template<class T>
    typename list<T>::iterator list<T>::insert(list::iterator pos, list::const_reference value) {
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

    template<class T>
    void list<T>::erase(list::iterator pos) {
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


    template<class T>
    void list<T>::push_back(list::const_reference value) {
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

    template<class T>
    void list<T>::pop_back() {
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

    template<class T>
    void list<T>::push_front(list::const_reference value) {
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

    template<class T>
    void list<T>::pop_front() {
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

    template<class T>
    void list<T>::swap(list<T> &other) {
        std::swap(head, other.head);
        std::swap(tails, other.tails);
        std::swap(list_size, other.list_size);
    }

    template<class T>
    void list<T>::merge(list<T> &other) {
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

    template<class T>
    void list<T>::splice(list::const_iterator pos, list<T> &other) {
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


    template<class T>
    void list<T>::reverse() {
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

    template<class T>
    void list<T>::unique() {
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

    // для этой функции нужен вектор
//    template <class T>
//    void list<T>::sort() {
//        if (head == nullptr || head->next == nullptr) {
//            return;
//        }
//
//
//    }
}