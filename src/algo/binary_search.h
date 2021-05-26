#ifndef _BINARY_SEARCH_H
#define _BINARY_SEARCH_H

#include <vector>

template<class T>
int binarySearch(std::vector<T>& values, T k) {
    int left = 0;
    int right = values.size() - 1;
    while (left <= right) {
        int m = (left + right) / 2;
        T val = values[m];
        if (val == k) {
            return m;
        }
        else if (k < val) {
            right = m - 1;
        }
        else {
            left = m + 1;
        }
    }
    return -1;
}

#endif