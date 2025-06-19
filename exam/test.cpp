//
// Created by smmm on 19.06.2025.
//

#include <map>
#include <vector>
#include <string>
#include <vector>
#include <iostream>

template<typename T>
void add(std::vector<T> v, const T& value)
{
	v.push_back(value);
}

template<typename T>
void addBase(std::vector<T> v, const T& value)
{
	try
	{
		v.push_back(value);
	}
	catch (...)
	{

	}
}

template<typename T>
void addStrong(std::vector<T> v, const T& value)
{
	try
	{
		std::vector<T> tmp{v};
		tmp.push_back(value);
		std::swap(v, tmp);
	}
	catch (...)
	{

	}
}


struct A
{
	std::string& r;
};

int main()
{
	std::string y{"123"};
	A t{y};
	std::cout << sizeof(t) << '\n';
	std::cout << sizeof(t.r) << '\n';
}
