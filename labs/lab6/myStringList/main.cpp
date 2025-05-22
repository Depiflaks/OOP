//
// Created by smmm on 22.05.2025.
//

#include "StringList.h"

#include <iostream>
int main()
{
	StringList list;
	list.PushBack("one");
	list.PushBack("two");
	list.PushBack("three");

	std::cout << *list.rend() << '\n';
	std::cout << *list.rbegin() << '\n';
	for (auto it = list.rbegin(); it != list.rend(); ++it)
	{
		std::cout << *it << " ";
	}
	return 0;
}