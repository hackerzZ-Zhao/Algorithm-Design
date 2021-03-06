//
// Created by 赵子葳 on 4/27/20.
//

#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper{
    int* generateRandomArray(int n, int rangeL, int rangeR){
        assert( rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n ; i ++){
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }
    int* generateNearlyOrderedArray(int n, int swapTimes){
        int *arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = i;

        srand(time(NULL));
        for(int i = 0; i < swapTimes; i ++){
            int posx = rand()%n;
            int posy = rand()%n;
            swap(arr[posx], arr[posy]);
        }

        return arr;
    }
    template<typename T>
    void printArray(T arr[], int n){
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";

        return;
    }

    template<typename T>
    bool isSorted(T arr[], int n){
        for(int i = 0; i < n - 1; i++){
            if(arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }
    template<typename T>
    void testSort(const string &sortName, void(*sort)(T[], int), T arr[], int n){
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;assert( isSorted(arr, n));

        assert(isSorted(arr, n));
        return;
    }
    int* copyIntArray(int a[], int n){
        int* arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }

}
#endif //SELECTIONSORT_SORTTESTHELPER_H
