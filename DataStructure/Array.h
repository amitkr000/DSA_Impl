#include <iostream>


class Array{
    private:
        int size;
        int current = -1;
        int* container;

    public:
        Array(int s);

        int get(int index);

        void push(int e);

        int pop();

        bool isEmpty();

        void reverseArray(int start, int end);

        int findMinimum();

        int findMaximum();

        int findSecondMax();

        int findSecondMin();

        void moveZeros();

        int findMissingNumber();

        ~Array();
};