#include <iostream>

class Dog {
public:
    Dog() : m_bones(nullptr) {
        m_bones = new int[100];
    }

    Dog(const Dog& other) {
        m_bones = new int[100];
        
        for (int i = 0; i < 100; ++i) {
            m_bones[i] = other.m_bones[i];
        }
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