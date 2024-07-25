#include <iostream>


class array{
    private:
        int size;
        int current = -1;
        int* container;

    public:
        array(int s){
            container = new int[s];
            size = s;
        }

        int get(int index){
            if (index >= 0 && index < size){
                return container[index];
            }
            else{
                std::cout << "\033[1;31mError! Invalid Index - " << index << "\033[0m\n";
                exit(0);
            }
        }

        void push(int e){
            if (size > current){
                current++;
                container[current] = e; 
            }
            else{
                std::cout << "\033[1;33mWarning! Array is Full. Can't add any more elements.\033[0m\n";
            }
        }

        void pop(){
            if (current >= 0){
                container[current] = '\0';
                current --;
            }
        }

        bool isEmpty(){
            if(current == -1){
                return true;
            }
            return false;
        }

        ~array(){
            std::cout << "Array destroyed" << std::endl;
            delete[] container;
        }
};

int main(){
    array a(3);
    a.push(10);
    std::cout << a.get(0) << std::endl;
    std::cout << a.isEmpty() << std::endl;
    a.pop();
    std::cout << a.isEmpty() << std::endl;
}