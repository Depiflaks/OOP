#include <iostream>
class Celsius;

class Celsius
{
	double degrees;
public:
	Celsius(double d) : degrees(d) { }
	
	double getDegrees() const {
		return degrees;
	}
};

class Fahrenheit
{
	double degrees;

public:
	Fahrenheit(double d) : degrees(d) { }

	operator Celsius() const {
		return Celsius((degrees - 32.0) * 5.0 / 9.0);
	}
};

void printTemperature(const Celsius& temp) {
	std::cout << temp.getDegrees() << "\n";
}

int main() {
	Celsius c(25.0);
	Fahrenheit f(77.0);

	printTemperature(c);

	printTemperature(f);

	return 0;
}
