#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

namespace s21 {
    template <class T>
    struct Node {
        T data;
        Node* prev;
        Node* next;
        explicit Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };
}

#endif //UNTITLED_NODE_H
