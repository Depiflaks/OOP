#include <iostream>
void foo(int x){
	std::cout << "1\n";
}

void foo(double x)
{
    std::cout << "2\n";
}

int main()
{
	foo(42);
	foo(3.14);

	return 0;
}
