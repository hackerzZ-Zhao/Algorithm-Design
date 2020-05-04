//
// Created by 赵子葳 on 4/29/20.
//

#ifndef MAXHEAP_HEAPSORT_H
#define MAXHEAP_HEAPSORT_H
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "Heap.h"
using namespace std;

template<typename T>
void heapSort1(T arr[], int n){
    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for(int i = 0; i < n; i ++){
        maxheap.insert(arr[i]);
    }
    for(int i = n - 1; i >= 0; i--){
        arr[i] = maxheap.extractMax();
    }
}
template<typename T>
void heapSort2(T arr[], int n){
    MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
    for(int i = n - 1; i >= 0; i--){
        arr[i] = maxheap.extractMax();
    }
}

#define MAXHEAP_HEAPSORT_H
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "Heap.h"
#include "HeapSort.h"

using namespace std;

template<typename T>
void __shiftDown(T arr[], int n, int k){
    while (2*k + 1 <= n){
        int j = 2*k + 1;
        if( j + 1 <= n && arr[j + 1] > arr[j]){
            j += 1;
        }
        if(arr[k] >= arr[j]) break;
        swap(arr[k], arr[j]);
        k = j;
    }
}
template<typename T>
void heapSort(T arr[], int n){
    for(int i = (n - 1) / 2; i >= 0; i -- ){
        __shiftDown(arr, n, i);
    }
    for(int i = n - 1; i > 0 ; i--){
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}
#endif //MAXHEAP_HEAPSORT_H
