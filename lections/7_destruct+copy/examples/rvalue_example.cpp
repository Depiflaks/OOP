int main() {
    int x = 1;
    int &&y = x + 1; // ok
    int &&b = x; // fail

    int &c = x + 1; // fail
    const int &d = x + 1; // ok

    int &&e = y; // fail, не rvalue
    int &f = y; // ok
} 