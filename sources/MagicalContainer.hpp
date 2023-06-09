#pragma once

#include <iostream>
#include <vector>

using namespace std;

#include "Iterator.hpp"

namespace ariel{
    class MagicalContainer {
        private:
            vector<int> arr;
            vector<int*> ascending;
            vector<int*> prime;
            vector<int*> cross;

        public:
            MagicalContainer();
            ~MagicalContainer();

            void addElement(int num);
            void removeElement(int num);
            int size();

            class AscendingIterator : public Iterator {
                public:
                    AscendingIterator(MagicalContainer& container);
                    AscendingIterator(vector<int*>& ref, unsigned int pointer);
                    AscendingIterator(const AscendingIterator& toCopy);

                    AscendingIterator begin() {return MagicalContainer::AscendingIterator(*this);}
                    AscendingIterator end() {return MagicalContainer::AscendingIterator(this->getArr(), this->getArr().size());}
            };

            class SideCrossIterator : public Iterator {
                public:
                    SideCrossIterator(MagicalContainer& container);
                    SideCrossIterator(vector<int*>& ref, unsigned int pointer);
                    SideCrossIterator(const SideCrossIterator& toCopy);

                    SideCrossIterator begin() {return MagicalContainer::SideCrossIterator(*this);}
                    SideCrossIterator end() {return MagicalContainer::SideCrossIterator(this->getArr(), this->getArr().size());}
            };

            class PrimeIterator : public Iterator {
                public:
                    PrimeIterator(MagicalContainer& container);
                    PrimeIterator(vector<int*>& ref, unsigned int pointer);
                    PrimeIterator(const PrimeIterator& toCopy);

                    PrimeIterator begin() {return MagicalContainer::PrimeIterator(*this);}
                    PrimeIterator end() {return MagicalContainer::PrimeIterator(this->getArr(), this->getArr().size());}
            };

            // inline getters ----------------------------------------------------------------

            vector<int*>& getAscending() {return ascending;}
            vector<int*>& getPrime() {return prime;}
            vector<int*>& getCross() {return cross;}

            // inline helper functions --------------------------------------------------------

            static bool isPrime(int num) {
                if(num <= 1) {
                    return false;
                }
                for(int i=2;i<(num/2)+1;i++) {
                    if(num % i == 0) {
                        return false;
                    }
                }
                return true;
            }
    };
}