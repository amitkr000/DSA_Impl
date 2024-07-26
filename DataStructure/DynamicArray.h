#include <iostream>

class DynamicArray{
    private:
        int m_totalSize;
        int m_currentSize;
        int* m_container;

        void resize();

    public:
        DynamicArray();

        int get(int i);

        int size();

        int totalSize();

        void append(int e);

        int pop();

        bool isEmpty();

        void insert(int i, int e);

        ~DynamicArray();
};