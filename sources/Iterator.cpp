#include <vector>
#include <iostream>

using namespace std;

#include "Iterator.hpp"

namespace ariel{
    Iterator& Iterator::operator=(const Iterator& other) {
        if(&this->arr != &other.arr) {
            throw runtime_error("cannot assign to different container iterator");
        }
        this->pointer = other.pointer;
        return *this;
    }

    int Iterator::operator*() { return *arr.at(pointer);}
    Iterator& Iterator::operator++() {
        if(pointer == arr.size()) {
            throw runtime_error("max size already");
        }
        ++pointer;
        return *this;
    }

    bool Iterator::operator!=(const Iterator& other) const {
        if (typeid(*this) != typeid(other)) {
            throw invalid_argument("not same type of iterator");
        }
        return pointer != other.getPointer();
    }
    bool Iterator::operator==(const Iterator& other) const {
        if (typeid(*this) != typeid(other)) {
            throw invalid_argument("not same type of iterator");
        }
        return pointer == other.getPointer();
    }
    bool Iterator::operator>(const Iterator& other) const {
        if (typeid(*this) != typeid(other)) {
            throw invalid_argument("not same type of iterator");
        }
        return pointer > other.getPointer();
    }
    bool Iterator::operator<(const Iterator& other) const {
        if (typeid(*this) != typeid(other)) {
            throw invalid_argument("not same type of iterator");
        }
        return pointer < other.getPointer();
    }
}