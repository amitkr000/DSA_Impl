#include <iostream>

void display(int arr[], int n){
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


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


int main(){
    int arr[10] = {12, 34, 76, 1, 56, 90, 31, 65, 29, 40};

    int n = sizeof(arr)/sizeof(arr[0]);

    display(arr, n);

    std::cout << "Insertion sort array: ";
    insertionSort(arr, n, true);

    std::cout << "Selection sort array: ";
    selectionSort(arr, n, true);

    std::cout << "Bubble Sort array: ";
    bubbleSort(arr, n, true);

    return 0;
}