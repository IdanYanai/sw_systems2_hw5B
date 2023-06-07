#include <vector>

using namespace std;

#include "Iterator.hpp"
#include "MagicalContainer.hpp"

namespace ariel{
    Iterator& Iterator::operator=(const Iterator& other) {
        this->arr = other.arr;
        this->pointer = other.pointer;
        return *this;
    }

    int Iterator::operator*() { return *pointer;}
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

    vector<int>::iterator Iterator::begin() {return arr->begin();}
    vector<int>::iterator Iterator::end() {return arr->end();}
}