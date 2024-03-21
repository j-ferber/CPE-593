#ifndef SEARCHER_H
#define SEARCHER_H

#include "Comparer.h"

template <typename T>
class Searcher {
public:
   // Returns the index of the key in the sorted array, or -1 if the key is not found
    static int BinarySearch(T* array, int arraySize, const T& key, Comparer<T>& comparer) {
        int left = 0;
        int right = arraySize - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (comparer.Compare(key, array[middle]) == 0) {
                return middle;
            } else if (comparer.Compare(key, array[middle]) < 0) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return -1;
    }
};

#endif
