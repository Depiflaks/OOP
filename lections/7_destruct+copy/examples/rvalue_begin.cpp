#include <iostream>

int main() {
    int x = 4;
    int &&y = x + 1;
    std::cout << &x << " " << &y << "\n";

    int &&z = std::move(x);

    z = z + 1;
    y = y + 1;

    std::cout << << x << " " << y << "\n";
}