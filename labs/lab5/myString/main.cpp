//
// Created by smmm on 16.05.2025.
//

#include <cstdlib>
int main()
{
	const char s_end = '\0';
	char* str;
	str = static_cast<char*>(malloc(1));

	*str = s_end;
}