//
// Created by smmm on 27.05.2025.
//

#include "findMax.h"

#include <iostream>
#include <vector>
int main()
{
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	int maxi;
	FindMax(v, maxi, std::greater());
	std::cout << maxi << std::endl;
	return 0;
}