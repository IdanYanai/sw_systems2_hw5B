#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#include "MagicalContainer.hpp"

namespace ariel{

    // Magical Container ------------------------------------------------------------

    MagicalContainer::MagicalContainer() {}
    MagicalContainer::~MagicalContainer() {}

    void MagicalContainer::addElement(int num) {
        arr.push_back(num);

        if(MagicalContainer::isPrime(num)) {
            prime.push_back(num);
            sort(prime.begin(), prime.end());
        }

        ascending.push_back(num);
        sort(ascending.begin(), ascending.end());

        MagicalContainer::crossSort(cross, arr);
    }
    void MagicalContainer::removeElement(int num) {
        arr.erase(remove(arr.begin(), arr.end(), num), arr.end());
        prime.erase(remove(prime.begin(), prime.end(), num), prime.end());
        ascending.erase(remove(ascending.begin(), ascending.end(), num), ascending.end());
        cross.erase(remove(cross.begin(), cross.end(), num), cross.end());
    }
    int MagicalContainer::size() {return arr.size();}

    // Iterators -------------------------------------------------------------------

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer container) {
        setArr(container.getAscending());
    }
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& toCopy) {
        setArr(toCopy.getArr());
        setPointer(toCopy.getPointer());
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer container) {
        setArr(container.getCross());
    }
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& toCopy) {
        setArr(toCopy.getArr());
        setPointer(toCopy.getPointer());
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer container) {
        setArr(container.getPrime());
    }
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& toCopy) {
        setArr(toCopy.getArr());
        setPointer(toCopy.getPointer());
    }
}