#include "list.h"

namespace s21 {

    template<class T>
    void list<T>::clear() {
        while (list_size) {
            pop_back();
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

    template <class T>
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

    template <class T>
    void list<T>::swap(list<T> &other) {
        std::swap(head, other.head);
        std::swap(tails, other.tails);
        std::swap(list_size, other.list_size);
    }

//    template <class T>
//    void list<T>::merge(list<T> &other) {}

    template <class T>
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

    template <class T>
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

//    template <class T>
//    void list<T>::sort() {
//        if (head == nullptr || head->next == nullptr) {
//            return;
//        }
//    }
}
