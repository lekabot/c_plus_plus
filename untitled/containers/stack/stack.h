#ifndef CONTAINERS_STACK_H
#define CONTAINERS_STACK_H

#include <cstddef>
#include <algorithm>
#include "../list/list.h"

namespace s21 {
    template<class T>
    class stack {
    public:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using size_type = size_t;

        stack() : data_() {}

        stack(std::initializer_list<value_type> const &items) : stack() {
            for (const auto& item : items) {
                push(item);
            }
        }

        stack(const stack &s) : data_(s.data_) {}

        stack(stack &&s) : data_(std::move(s.data_)) {}

        ~stack() = default;

        stack& operator=(const stack &s) {
            if (this != &s) {
                data_ = s.data_;
            }
            return *this;
        }

        stack& operator=(stack &&s) noexcept {
            if (this != &s) {
                data_ = std::move(s.data_);
            }
            return *this;
        }

        const_reference top() const {
            return data_.front();
        }

        bool empty() const {
            return data_.empty();
        }

        size_type size() const {
            return data_.size();
        }

        void push(const_reference value) {
            data_.push_front(value);
        }

        void pop() {
            data_.pop_front();
        }

        void swap(stack& other) {
            std::swap(data_, other.data_);
        }

    private:
        list<value_type> data_;
    };
}

#endif //CONTAINERS_STACK_H
