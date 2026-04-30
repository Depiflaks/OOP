#include <iostream>

struct Data {
    int value;
};

class Iterator {
    Data* ptr;
public:
    Iterator(Data* p) : ptr(p) {}

    Iterator operator--(int) {
        std::cout << "op op op op\n";
        return ptr;
    }

    Data* operator->() {
        return ptr;
    }
};

int main() {
    Data arr[3] = {{10}, {20}, {30}};
    Iterator it(&arr[2]);

    std::cout << it--->value << "\n"; 
    std::cout << it--->value << "\n"; 
    std::cout << it--->value << "\n"; 

    return 0;
}