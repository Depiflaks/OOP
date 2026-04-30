class LambdaKiller {
    int multiplier;
public:
    LambdaKiller(int m) : multiplier(m) {}

    int operator()(int value) const {
        return value * multiplier;
    }
};

int main() {
    LambdaKiller timesFive(5);
    
    int result1 = timesFive(10);
    int result2 = timesFive(20);
    
    return 0;
}