#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#include "MagicalContainer.hpp"
#include "Iterator.hpp"

namespace ariel{

    // Magical Container ------------------------------------------------------------

    MagicalContainer::MagicalContainer() {}
    MagicalContainer::~MagicalContainer() {}

    void MagicalContainer::addElement(int num) {
        arr.push_back(num);
        unsigned int n = arr.size();

        // reset pointers
        prime.clear();
        ascending.clear();
        for(unsigned int i=0;i<n;i++) {
            if(MagicalContainer::isPrime(arr[i])) {
                prime.push_back(&arr[i]);
            }
            ascending.push_back(&arr[i]);
        }

        // sort ascending with lambda function
        sort(ascending.begin(), ascending.end(), [](int* a, int* b) {return *a<*b;});

        // reset SideCross pointers and order
        cross.clear();
        for(unsigned int i=0;i<n; i++) {
            if(i%2==0) {
                cross.push_back(&arr[i/2]);
            }
            else {
                cross.push_back(&arr[n - i/2 - 1]);
            }
        }
    }
    void MagicalContainer::removeElement(int num) {
        auto it = find(arr.begin(), arr.end(), num);
        if(it == arr.end()) {
            throw runtime_error("num to erase doesnt exist");
        }

        // first remove pointers
        prime.erase(remove(prime.begin(), prime.end(), &(*it)), prime.end());
        ascending.erase(remove(ascending.begin(), ascending.end(), &(*it)), ascending.end());
        cross.erase(remove(cross.begin(), cross.end(), &(*it)), cross.end());

        // then remove value
        arr.erase(remove(arr.begin(), arr.end(), num), arr.end());
    }
    int MagicalContainer::size() {return arr.size();}

    // Iterators -------------------------------------------------------------------

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
    : Iterator(container.getAscending(), 0) {}
    MagicalContainer::AscendingIterator::AscendingIterator(vector<int *>& ref, unsigned int pointer)
    : Iterator(ref, pointer) {}
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& toCopy)
    : Iterator(toCopy.getArr(), toCopy.getPointer()) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
    : Iterator(container.getCross(), 0) {}
    MagicalContainer::SideCrossIterator::SideCrossIterator(vector<int *> &ref, unsigned int pointer)
    : Iterator(ref, pointer) {}
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& toCopy)
    : Iterator(toCopy.getArr(), toCopy.getPointer()) {}

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
    : Iterator(container.getPrime(), 0) {}
    MagicalContainer::PrimeIterator::PrimeIterator(vector<int *> &ref, unsigned int pointer)
    : Iterator(ref, pointer) {}
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& toCopy)
    : Iterator(toCopy.getArr(), toCopy.getPointer()) {}
}