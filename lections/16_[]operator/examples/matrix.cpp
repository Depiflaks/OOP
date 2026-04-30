#include <vector>

class Matrix {
    int rows;
    int cols;
    std::vector<std::vector<int>> data;
public:
    Matrix(int r, int c) : rows(r), cols(c), data(r, std::vector<int>(c, 0)) {}
    
    std::vector<int>& operator[](int index) {
        return data[index];
    }

    const std::vector<int>& operator[](int index) const {
        return data[index];
    }
};