#include <vector>
#include <iostream>

using namespace std;

#include "Iterator.hpp"

namespace ariel{
    Iterator& Iterator::operator=(const Iterator& other) {
        this->arr = other.arr;
        this->pointer = other.pointer;
        return *this;
    }

    int Iterator::operator*() { return *arr.at(pointer);}
    void Iterator::operator++() {++pointer;}

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

    Iterator Iterator::begin() {return Iterator(this->arr, (unsigned int)(0));}
    Iterator Iterator::end() {return Iterator(this->arr, (unsigned int)(arr.size()));}
}