#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "MergeSort.h"

using namespace std;

template<typename T>
void mergeSortBU(T arr[], int n){
    for(int size = 1; size <= n; size += size){
        for (int i = 0; i + size < n; i += 2 * size) {
            __merge(arr, i, i + size - 1, min(i + 2 * size - 1, n - 1));
        }
    }
}

int main() {
    int n = 50000;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort BU", mergeSortBU, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

    delete[] arr1;
    delete[] arr2;
    return 0;
}
