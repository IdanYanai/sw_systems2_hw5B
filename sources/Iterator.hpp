// interface for all iterators
#pragma once

#include <vector>

using namespace std;

namespace ariel{
    class Iterator {
    private:
        vector<int*>& arr;
        unsigned int pointer;

    public:
        Iterator& operator=(const Iterator& other);

        Iterator(vector<int*>& ref) : arr(ref) {}
        Iterator(vector<int*>& ref, unsigned int ptr) : arr(ref), pointer(ptr) {}
        virtual ~Iterator() {}

        int operator*();
        void operator++();

        bool operator!=(const Iterator& other) const;
        bool operator==(const Iterator& other) const;
        bool operator>(const Iterator& other) const;
        bool operator<(const Iterator& other) const;

        Iterator begin();
        Iterator end();

        // inline set, get
        vector<int*>& getArr() const {return arr;}
        void setArr(vector<int*>& arr) {this->arr = arr;}
        unsigned int getPointer() const {return pointer;}
        void setPointer(unsigned int pointer) {this->pointer=pointer;}
    };
}