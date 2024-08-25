#include <iostream>
#include <string>

// Improvement of binary search used for "uniformly" distributed "guess" by calculating 
// the probability(prob) of index of an element. if the 
// element is greater than or less the element at prob, then we shift the search area
// and calculate the new prob.
// Need a sorted array.
// avg case  : o(log(log(n)))   [elements are uniformly distributed]
// worst case: o(n)             [elements increases exponentially]
int interpolationSearch(int arr[], int n, int value, bool debug = false){
    int low = 0;
    int high = n - 1;
    int prob = 0;

    while (value >= arr[low] && value <= arr[high] && low <= high){
        if (low == high) prob = low; // to prevent division by 0
        else prob = low + (high - low) * (value - arr[low]) / (arr[high] - arr[low]);

        if (debug) std::cout << "prob is :" << prob << std::endl;

        if (value < arr[prob]) high = prob - 1;
        else if (value > arr[prob]) low = prob + 1;
        else{
            if (debug) std::cout << "Element is at index: " << prob << std::endl;
            return prob;
        } 
    }

    if (debug) std::cout << "Element does not exists in the array." << std::endl;
    return -1;
}

// Searching Alogrithm works on a sorted array, it calculate the middle index and if the 
// middle element is not the element searchig, then compare the middle element is 
// greater or less then with low or high index element. and shift the search area by changing
// low or high value accordingly and calculate the new middle index.
// avg case  : o(log(n))
// worst case: o(log(n))
int binarySearch(int arr[], int n, int value, bool debug = false){
    int low = 0;
    int high = n - 1;

    int middle = (high - low) / 2;

    while (value >= arr[low] && value <= arr[high] && low <= high){
        middle = low + (high - low) / 2;

        if (debug) std::cout << "middle is :" << middle << std::endl;

        if (value < arr[middle]) high = middle - 1;
        else if (value > arr[middle]) low = middle + 1;
        else{
            if (debug) std::cout << "Element is at index: " << middle << std::endl;
            return middle;
        }
    }

    if (debug) std::cout << "Element does not exists in the array." << std::endl;
    return -1;
}

// Searching algorithm that does not need sorted array, it start searching from start
// of an array and check all the element one after another is equal to the searching element.
// worst case: o(n^2)
int linearSearch(int arr[], int n, int value, bool debug = false){
    for (int i = 0; i < n; i++){
        if (value == arr[i]){
            if (debug) std::cout << "Element is at index: " << i << std::endl;
            return i;
        }
    }

    if (debug) std::cout << "Element does not exists in the array." << std::endl;
    return -1;
}


void displayArray(int arr[], int n, std::string msg){
    
    std::cout << msg;
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int arr[] = {2, 4, 7, 12, 15, 18, 50, 250, 1200, 3000};
    int n = sizeof(arr)/sizeof(arr[0]);
    displayArray(arr, n, "sorted array: ");

    int index = interpolationSearch(arr, n, 1, true);

    index = binarySearch(arr, n, 1, true);

    index = linearSearch(arr, n, 1, true);
    
    return 0;
}
