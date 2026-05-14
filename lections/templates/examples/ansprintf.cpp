#include <iostream>
#include <cstdio>

int main() {
    int age = 20;
    const char* name = "Alex";

    printf("Age: %s\n", age);
    printf("Name: %f\n", name);

    std::cout << "Age: " << age << std::endl;
    std::cout << "Name: " << name << std::endl;

    return 0;
}