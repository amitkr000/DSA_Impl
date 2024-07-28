#include <iostream>

class SinglyLinkedList{
    struct node{
        int data = 0;
        SinglyLinkedList* next = NULL;
    };

    private:
        node* head;

    public:
        SinglyLinkedList();

        void insertNode(int i, int data);

        void insertBegin(int data);

        void insertAtEnd(int data);

        void insertSorted(int data);

        void printLinkedList();

        int deleteNode(int i);

        int deleteBegin();

        int deleteAtEnd();

        int deleteSpecific(int data);

        int pop();

        bool isEmpty();

        int findElement();

        void reverse();

        int findFromLast();

        void removeDuplicate();

        void removeSortedDuplicate();

        bool hasLoop();

        node startNodeLoop();

        void removeLoop();

};