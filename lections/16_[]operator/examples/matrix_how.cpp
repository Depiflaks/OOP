#include <vector>
class Matrix
{
	int rows;
	int cols;
	std::vector<std::vector<int>> data;

public:
	Matrix(int r, int c)
		: rows(r)
		, cols(c)
		, data(r, std::vector<int>(c, 0))
	{
	}

	// int* operator[](int index) { return data[index]; } // а как?
};
