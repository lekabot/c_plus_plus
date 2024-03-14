#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

namespace s21 {
    template <class T>
    struct Node {
        T data;
        Node* prev;
        Node* next;
//        Node() : next(nullptr), prev(nullptr) {}
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };
}

#endif //UNTITLED_NODE_H
