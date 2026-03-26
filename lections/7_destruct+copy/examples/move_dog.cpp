#include <iostream>

class Dog {
public:
    Dog() : m_bones(nullptr) {
        m_bones = new int[100];
    }

    Dog(Dog&& other) : m_bones(other.m_bones) {
        other.m_bones = nullptr;
    }

private:
    int* m_bones;
};

void GoToWalk() {
    Dog sharik{};
}

int main() {
    while (true) {
        GoToWalk();
    }
}