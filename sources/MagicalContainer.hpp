#pragma once

#include <iostream>
#include <vector>

using namespace std;

#include "Iterator.hpp"

namespace ariel{
    class MagicalContainer {
        private:
            vector<int> arr;
            vector<int> ascending;
            vector<int> prime;
            vector<int> cross;

        public:
            MagicalContainer();
            ~MagicalContainer();

            void addElement(int num);
            void removeElement(int num);
            int size();

            class AscendingIterator : public Iterator {
                public:
                    AscendingIterator(MagicalContainer container);
                    AscendingIterator(const AscendingIterator& toCopy);
            };

            class SideCrossIterator : public Iterator {
                public:
                    SideCrossIterator(MagicalContainer container);
                    SideCrossIterator(const SideCrossIterator& toCopy);
            };

            class PrimeIterator : public Iterator {
                public:
                    PrimeIterator(MagicalContainer container);
                    PrimeIterator(const PrimeIterator& toCopy);
            };

            // inline getters
            vector<int>* getAscending() {return &ascending;}
            vector<int>* getPrime() {return &prime;}
            vector<int>* getCross() {return &cross;}

            // static helper functions --------------------------------------------------------

            void crossSort(vector<int>& arr, vector<int> toSort) {
                arr.resize(toSort.size(), 0);
                for(unsigned int i=0;i<toSort.size(); i++) {
                    if(i%2==0) {
                        arr.at(i) = toSort.at(i/2);
                    }
                    else {
                        arr.at(i) = toSort.at(toSort.size() - i/2 - 1);
                    }
                }
            }

            bool isPrime(int num) {
                for(int i=2;i<(num/2)+1;i++) {
                    if(num % i == 0) {
                        return false;
                    }
                }
                return true;
            }
    };
}