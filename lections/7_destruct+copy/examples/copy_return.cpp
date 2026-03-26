#include <iostream>

class Foo {
public:
    Foo() {
        std::cout << "Create\n";
    }

    Foo(const Foo& other) {
        std::cout << "Copy\n";
    }

    ~Foo() {
        std::cout << "RIP\n";
    }

    int m_value{3};
};

Foo why() {
    Foo f{};
    return f;
}

Foo& bad() {
    Foo f{};
    return f;
}

const Foo& alsoBad() {
    Foo f{};
    return f;
}

const Foo& good() {
    const Foo& f{};
    return f;
}


void bar() {
    std::cout << "bar start\n";
    const Foo& f = alsoBad();
    std::cout << f.m_value << "\n";
    std::cout << "bar end\n";
}

int main() {
    std::cout << "start\n";
    bar();
    std::cout << "end\n";
}