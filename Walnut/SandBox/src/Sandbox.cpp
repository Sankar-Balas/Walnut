#include<iostream>
#include"sandbox.h"

namespace Walnut {
	__declspec (dllexport) void Print();
}

int main()
{
	Walnut::Print();
	std::getchar();
	return 0;
}
