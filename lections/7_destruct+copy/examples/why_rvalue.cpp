struct S {
    int n = 0;
    int& access() {return n;}
}

// скомпилировать и объяснить, что он отлично отрабатывает без &

int main() {
    S x;
    int& y = x.access();
    int& z = S{}.access(); // dead parrot
}
