#include <iostream>
#include "Log.h"

struct C {
	int b;
};

int main()
{
	int a = 8;
	C c{ 2 };
	a++;
	const char *string = "Hello";
	for (int i = 0;  i < 5; ++i) {
		const auto& c = *(string + i);
		std::cout << c << std::endl;
	}
	Log("Hello world!");
	std::cin.get();
}

