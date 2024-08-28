#include <iostream>

void display(int arr[], int n){
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


// Bubble Sort ------------------------------------------------

// Bubble sorting works on swap the adjacement elements in unsorted section while iterating 
// and place the element at sorted position in the array. In one iteration one element
// is placed at its sorted position. repeating the step "size of array" times.

/// @brief Bubble sorting algorithm
/// @param arr array to sort
/// @param n size of array
/// @param debug enable/disable debugging output
void bubbleSort(int arr[], int n, bool debug = false){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    if (debug) display(arr, n);
}


// Selection Sort ------------------------------------------------

// Selection sorting works on finding the min element index in unsorted array section while
// iterating and at the end of iteration, placing the min element at just one index before/after 
// the start/end of sorted array section through swaping, repeating the step "size of array" times.

/// @brief Selection sorting algorithm
/// @param arr array to sort
/// @param n size of array
/// @param debug enable/disable debugging output
void selectionSort(int arr[], int n, bool debug = false){
    for (int i = 0; i < n; i++){
        int min = 0;
        for (int j = 1; j < n - i; j++){
            if (arr[min] > arr[j]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    if (debug) display(arr, n);
}


// Insertion Sort ------------------------------------------------

// Insertion sort works on iterating over the array and sorting the left size of array of ith 
// element by swaping so it divide the array into two part left size of ith element is sorted
// and right side of element and also the element is unsorted.

/// @brief Insertion sorting algorithm
/// @param arr array to sort
/// @param n size of array
/// @param debug enable/disable debugging output
void insertionSort(int arr[], int n, bool debug=false){
    for (int i = 1; i < n; i++){
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j + 1]){
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            j--;
        }
    }
    if (debug) display(arr, n);
}


// Merge Sort ------------------------------------------------

void merge(int leftarr[], int rightarr[], int Lsize, int Rsize, int arr[]){
    int i = 0, j = 0, k = 0;

    while (j < Lsize & k < Rsize)
    {
        if (leftarr[j] < rightarr[k]){
            arr[i] = leftarr[j];
            i++;
            j++;
        }
        else{
            arr[i] = rightarr[k];
            i++;
            k++;
        }
    }
    
    while (j < Lsize){
        arr[i] = leftarr[j];
        i++;
        j++;
    }

    while (k < Rsize)
    {
        arr[i] = rightarr[k];
        i++;
        k++;
    }
    
}

void mergeSortHelper(int arr[], int n){
    int length = n;

    if (length <= 1){
        return;
    }

    int middle = length/2;
    int leftarr[middle];
    int rightarr[length - middle];

    int j = 0;
    for (int i = 0; i < length; i++){
        if (i < middle) leftarr[i] = arr[i];
        else {
            rightarr[j] = arr[i];
            j++;
        }
    } 

    mergeSortHelper(leftarr, middle);
    mergeSortHelper(rightarr, length - middle);

    merge(leftarr, rightarr, middle, length - middle, arr);
}

// Divide the array from middle element into Left and right subarray, repeat the step until the subarray 
// have 1 element, then from last subarrays start merge the left and right subarray by comparing
// at the appropriate  the left subarray element to right one and inserting into the array(from which 
// the left and right subarray made)index to sort in accesending/decending order. Repeat the step untill 
// reach the original array.

/// @brief Merge sorting algorithm
/// @param arr array to sort
/// @param n size of array
/// @param debug enable/disable debugging output
void mergeSort(int arr[], int n, bool debug = false){
    mergeSortHelper(arr, n);

    if (debug) display(arr, n);
}


// Quick Sort ------------------------------------------------

void quickSortHelper(int arr[], int start, int end){
    if (end - start + 1 <= 1) return;

    int i = -1, j = 0;
    int pivot = end;

    while (j < pivot){
        if (arr[j] < arr[pivot]){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }

    i++;
    int temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;


    int pivot_pos = i;

    quickSortHelper(arr, start, pivot - 1);
    quickSortHelper(arr, pivot + 1, end);

}

// Selecting a pivot elemets(which could be and element preffered is Last, first, middle) and
// placing the pivot element into the its sorted position such that left side of pivot is smaller
// then pivot and right side is larger then pivot, after that repeat the above step for the left
// side and right side array until the Length of left and right side array remain 1. 

/// @brief Quick sorting algorithm
/// @param arr array to sort
/// @param n size of array
/// @param debug enable/disable debugging output
void quickSort(int arr[], int n, bool debug = false){
    quickSortHelper(arr, 0, n - 1);

    if (debug) display(arr, n);
}

