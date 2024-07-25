#include <iostream>
#include "Array.h"

Array::Array(int s){
    size = s;
    container = new int[size];
}

int Array::get(int index){
    if (index >= 0 && index < size){
        return container[index];
    }
    else{
        std::cout << "\033[1;31m[Error]! Invalid Index - " << index << "\033[0m\n";
        exit(0);
    }
}

void Array::push(int e){
    if (size > current){
        current++;
        container[current] = e; 
    }
    else{
        std::cout << "\033[1;33m[Warn]! Array is Full. Can't add any more elements.\033[0m\n";\
        exit(0);
    }
}

int Array::pop(){
    if (current >= 0){
        int temp = container[current];
        container[current] = '\0';
        current --;
        return temp;
    }
    else{
        std::cout << "\033[1;31m[Error]! Invalid Pop Operation - Array is Empty" << "\033[0m\n";
        exit(0);
    }
}

bool Array::isEmpty(){
    if(current == -1){
        return true;
    }
    return false;
}

Array::~Array(){
    std::cout << "\033[1;32m[Info]! Array destroyed\033[0m" << std::endl;
    delete[] container;
}

void Array::reverseArray(int start, int end){
    while (start > end){
        int temp = container[start];
        container[start] = container[end];
        container[end] = temp;
        start++;
        end--;
    }
}

int Array::findMaximum(){
    int max = container[0];
    for (int i=1; i< size; i++){
        if (container[i] > max){
            max = container[i];
        }
    }
    return max;
}

int Array::findMinimum(){
    int min = container[0];
    for (int i=1; i< size; i++){
        if (container[i] < min){
            min = container[i];
        }
    }
    return min;
}

int Array::findSecondMax(){
    int max = container[0];
    int secondMax = container[0];

    for (int i = 1; i < size; i++){
        if (container[i] > max){
            secondMax = max;
            max = container[i];
        }
        else if (secondMax < container[i] && container[i] < max)
        {
            secondMax = container[i];
        }
    }
    return secondMax;
}

int Array::findSecondMin(){
    int min = container[0];
    int secondMin = container[0];

    for (int i = 1; i < size; i++){
        if (container[i] < min){
            secondMin = min;
            min = container[i];
        }
        else if (secondMin > container[i] && container[i] > min)
        {
            secondMin = container[i];
        }
    }
    return secondMin;
}

void Array::moveZeros(){
    int zeroptr = 0;

    for (int nonZeroptr = 0; nonZeroptr < size; nonZeroptr++){
        if (container[zeroptr] == 0 && container[nonZeroptr] != 0){
            container[zeroptr] = container[nonZeroptr];
            container[nonZeroptr] = 0; 
        }
        if (container[zeroptr] != 0){
            zeroptr++;
        }
    }
}

int Array::findMissingNumber(){
    int n = size + 1;
    int sum = n*(n+1)/2;
    for (int i = 0; i < size; i++){
        sum -= container[i];
    }
    return sum;
}

int main(){
    Array a(3);
    a.push(10);
    std::cout << a.get(0) << std::endl;
    std::cout << a.isEmpty() << std::endl;
    a.pop();
    std::cout << a.isEmpty() << std::endl;
} 