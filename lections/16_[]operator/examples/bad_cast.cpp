#include <iostream>
class SmartPointer {
    int* ptr;
public:
    SmartPointer(int* p) : ptr(p) {}
    
    operator bool() const {
        return ptr != nullptr;
    }
};

int main() {
    int value = 42;
    SmartPointer p1(&value);
    SmartPointer p2(&value);
    
    int unexpectedResult = p1 + p2 + 10;
    std::cout << unexpectedResult << "\n";
    return 0;
}