// interface for all iterators
#pragma once

#include <vector>

using namespace std;

namespace ariel{
    class Iterator {
    private:
        vector<int>* arr;
        vector<int>::iterator pointer;

    public:
        Iterator& operator=(const Iterator& other);
        virtual ~Iterator() {}

        int operator*();
        void operator++();

        bool operator!=(const Iterator& other) const;
        bool operator==(const Iterator& other) const;
        bool operator>(const Iterator& other) const;
        bool operator<(const Iterator& other) const;

        vector<int>::iterator begin();
        vector<int>::iterator end();

        // inline set, get
        vector<int>* getArr() const {return arr;}
        void setArr(vector<int>* arr) {this->arr = arr;}
        vector<int>::iterator getPointer() const {return pointer;}
        void setPointer(vector<int>::iterator pointer) {this->pointer=pointer;}
    };
}