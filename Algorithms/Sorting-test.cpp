#include <iostream>
#include "Sorting.h"


int main(){
    int arr[10] = {12, 34, 76, 1, 56, 90, 31, 65, 29, 40};

    int n = sizeof(arr)/sizeof(arr[0]);
    display(arr, n);


    std::cout << "--------------- Sorted Array -----------------" << std::endl;

    std::cout << "Quick sort array: ";
    quickSort(arr, n, true);

    // std::cout << "Insertion sort array: ";
    // insertionSort(arr, n, true);

    // std::cout << "Selection sort array: ";
    // selectionSort(arr, n, true);

    // std::cout << "Bubble Sort array: ";
    // bubbleSort(arr, n, true);

    return 0;
}