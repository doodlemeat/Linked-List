#include <iostream>
#include "LinkedListTest.h"

int main()
{
	testPushFront();
	testPushBack();
	testPopFront();
	testPopBack();
	testErase();
	testSearch();
	testClear();
	testSize();

	std::cout << "All tests passed!" << std::endl;

	return 0;
}