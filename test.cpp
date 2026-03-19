#include <iostream>

class Teacher {
public:
    Teacher() { std::cout << "Teacher\n"; }
};

class Masha {
    Teacher t;
public:
    Masha() { std::cout << "Masha\n"; }
};

class Petya {
public:
    Petya() { std::cout << "Petya\n"; }
};

class Vasya {
    Masha m;
    Petya p;
public:
    Vasya() { std::cout << "Vasya\n"; }
};

int main() {
    Vasya v;
    return 0;
}