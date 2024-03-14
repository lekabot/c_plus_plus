#ifndef CONTAINERS_QUEUE_H
#define CONTAINERS_QUEUE_H

#include <cstddef>
#include <algorithm>
#include "../list/list.h"

namespace s21 {
    template<class T>
    class queue {
    public:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using size_type = size_t;

        queue() : data_() {}
        queue(std::initializer_list<value_type> const &items) : data_(items) {}
        queue(const queue& q) : data_(q.data_) {}
        queue(queue &&q)  noexcept : data_(std::move(q.data_)) {}
        ~queue() = default;

        queue& operator=(const queue &q) {
            if (this != &q) {
                data_ = q.data_;
            }
            return *this;
        }

        queue& operator=(queue &&q) noexcept {
            if (this != &q) {
                data_ = std::move(q.data_);
            }
            return *this;
        }

        const_reference front() { return data_.front(); }
        const_reference back() { return data_.back(); }

        bool empty() { return data_.empty(); }
        size_type size() { return data_.size(); }

        void push(const_reference value) { data_.push_back(value); }
        void pop() { data_.pop_front(); }
        void swap(queue& other) { std::swap(data_, other.data_); }


    private:
        list<value_type> data_;
    };

}

#endif //CONTAINERS_QUEUE_H
