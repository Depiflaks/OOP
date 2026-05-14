#include <iostream>
#include <cstdio>

int main() {
    int age = 20;
    const char* name = "Alex";

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;

    return 0;
}
