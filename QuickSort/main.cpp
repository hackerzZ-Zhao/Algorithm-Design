#include <iostream>
#include "MergeSort.h"
#include "SortTestHelper.h"
#include "QuickSort.h"
using namespace std;

template<typename T>
void __quickSort3ways(T arr[], int l, int r){
//    if(l >= r){
//        return;
//    }
    if(r - l <= 15){
        insertionSort(arr, l, r);
        return;
    }
    //partition
    swap(arr[l], arr[rand()%(r - l + 1) + l]);
    T v = arr[l];

    int lt = l;
    int gt = r + 1;
    int i = l + 1;
    while (i < gt){
        if(arr[i] < v){
            swap(arr[i], arr[lt + 1]);
            lt ++;
            i ++;
        }
        else if (arr[i] > v){
            swap(arr[i], arr[gt - 1]);
            gt --;
        }
        else{
            i ++;
        }
    }
    swap(arr[l], arr[lt]);
    __quickSort3ways(arr, l, lt - 1);
    __quickSort3ways(arr, gt, r);
}

template<typename T>
void quickSort3ways(T arr[], int n) {
    srand(time(NULL));
    __quickSort3ways(arr, 0, n - 1);
}

int main() {
    int n = 1000000;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Quick Sort2", quickSort2, arr1, n);
    SortTestHelper::testSort("Quick Sort3", quickSort3ways, arr2, n);

    int swaptime = 100;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swaptime);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr1, n);
    SortTestHelper::testSort("Quick Sort3", quickSort3ways, arr2, n);

    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr1, n);
    SortTestHelper::testSort("Quick Sort3", quickSort3ways, arr2, n);
    delete[] arr1;
    delete[] arr2;
    return 0;
}
