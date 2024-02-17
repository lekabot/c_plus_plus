#include <iostream>
#include <deque>

int main() {
    std::deque<int> myDeque = {1, 2, 3, 4, 5};
    std::deque<int>::iterator it = myDeque.begin();

//    for (auto it = myDeque.begin(); it != myDeque.end(); ++it) {
//        std::cout << *it << " ";
//    }
//    std::cout << std::endl;

    std::cout<<*it<<std::endl;

    return 0;
}
