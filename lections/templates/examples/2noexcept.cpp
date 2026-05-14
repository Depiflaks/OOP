#include <iostream>
#include <stdexcept>

void DangerousFunction() {
    throw std::runtime_error("Something went wrong");
}

void NoexceptFunction() noexcept {
    DangerousFunction();
}

int main() {
    try {
        NoexceptFunction();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "Program continues" << std::endl;

    return 0;
}
