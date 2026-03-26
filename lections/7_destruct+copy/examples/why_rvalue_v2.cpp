struct S {
    int n = 0;
    int& access() & {return n;}
}

// next
struct S {
    int n = 3;
    int foo() & {
        return n;
    };

    int foo() && {
        return 3;
    };
}


int main() {
    S x;
    int& y = x.access();
    int& z = S{}.access(); // compilation error!
}
