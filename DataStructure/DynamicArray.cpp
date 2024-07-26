#include <iostream>
#include "DynamicArray.h"

DynamicArray::DynamicArray(){
    m_currentSize = 0;
    m_totalSize = 1;
    m_container = new int[m_totalSize];
}

int DynamicArray::get(int i){
    if (i > 0 && i < m_currentSize){
        return m_container[i];
    }
    std::cout << "\033[1;31m[Error]! Invalid Index - " << i << "\033[0m\n";
    exit(0);
}

int DynamicArray::size(){
    return m_currentSize;
}

int DynamicArray::totalSize(){
    return m_totalSize;
}

void DynamicArray::append(int e){
    if (m_currentSize < m_totalSize){
        m_container[m_currentSize] = e;
        m_currentSize++;
    }
    else if(m_currentSize == m_totalSize){
        resize();
        m_container[m_currentSize] = e;
        m_currentSize++;
    }
}

void DynamicArray::insert(int i, int e){
    if (i > 0 && i < m_currentSize){
        m_container[i] = e;
    }
    std::cout << "\033[1;31m[Error]! Out of Range Index - " << i << "\033[0m\n";
    exit(0);
}

void DynamicArray::resize(){
    m_totalSize = 2*m_totalSize;
    int* temp = new int[m_totalSize];
    for (int i = 0; i < m_currentSize; i++){
        temp[i] = m_container[i];
    }
    delete[] m_container;
    m_container = temp;
}

int DynamicArray::pop(){
    if (m_currentSize > 0){
        int temp = m_container[m_currentSize-1];
        m_container[m_currentSize - 1] = '\0';
        m_currentSize--;
        return temp;
    }
    std::cout << "\033[1;31m[Error]! Invalid Pop Operation - Array is Empty" << "\033[0m\n";
    exit(0);
}

bool DynamicArray::isEmpty(){
    if (m_currentSize == 0){
        return true;
    }
    return false;
}

DynamicArray::~DynamicArray(){
    std::cout << "\033[1;32m[Info]! Array destroyed\033[0m" << std::endl;
    delete[] m_container;
}

int main(){
    DynamicArray da;
    da.append(10);
    std::cout << "Size of Array: " << da.size() << std::endl;
    std::cout << "TotalSize of Array: " << da.totalSize() << std::endl;
    da.append(11);
    std::cout << "Size of Array: " << da.size() << std::endl;
    std::cout << "TotalSize of Array: " << da.totalSize() << std::endl;
    std::cout << da.get(1) << std::endl;
    da.append(12);
    std::cout << "Size of Array: " << da.size() << std::endl;
    std::cout << "TotalSize of Array: " << da.totalSize() << std::endl;
    std::cout << da.get(2) << std::endl;
}