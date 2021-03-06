//
// Created by 赵子葳 on 4/28/20.
//

#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H
#include <iostream>
#include "MergeSort.h"
#include "SortTestHelper.h"
using namespace std;


template<typename T>
int __partition(T arr[], int l, int r){
    swap(arr[l], arr[rand()%(r - l + 1) + l]);
    T v = arr[l];

    int j = l;
    for (int i = l + 1; i <= r; i++){
        if(arr[i] < v){
            swap(arr[j + 1], arr[i]);
            j ++;
        }
    }
    swap(arr[l], arr[j]);
    return j;
}


template<typename T>
void __quickSort(T arr[], int l, int r){
//    if(l >= r){
//        return;
//    }
    if(r - l <= 15){
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

template<typename T>
void quickSort(T arr[], int n) {
    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}
template<typename T>
int __partition2(T arr[], int l, int r){
    swap(arr[l], arr[rand()%(r - l + 1) + l]);
    T v = arr[l];

    int i = l + 1, j = r;
    while (true){
        while(i <= r && arr[i] < v) i ++;
        while(j >= l + 1 && arr[j] > v) j --;
        if(i > j) break;
        swap(arr[i], arr[j]);
        i ++;
        j --;
    }
    swap(arr[l], arr[j]);
    return j;
}


template<typename T>
void __quickSort2(T arr[], int l, int r){
//    if(l >= r){
//        return;
//    }
    if(r - l <= 15){
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p - 1);
    __quickSort2(arr, p + 1, r);
}

template<typename T>
void quickSort2(T arr[], int n) {
    srand(time(NULL));
    __quickSort2(arr, 0, n - 1);
}
#endif //QUICKSORT_QUICKSORT_H
