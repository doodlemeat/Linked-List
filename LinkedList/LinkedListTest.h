#pragma once
#include <assert.h>
#include "LinkedList.h"

void testPushFront()
{
	LinkedList<int> list;
	list.push_front(1);
	assert(list[0] == 1);
	list.push_front(2);
	assert(list[0] == 2);
	list.push_front(3);
	assert(list[0] == 3);
	list.push_front(4);
	assert(list[0] == 4);
	list.push_front(5);
	assert(list[0] == 5);
}

void testPushBack()
{
	LinkedList<int> list;
	list.push_back(1);
	assert(list[list.size() - 1] == 1);
	list.push_back(2);
	assert(list[list.size() - 1] == 2);
	list.push_back(3);
	assert(list[list.size() - 1] == 3);
	list.push_back(4);
	assert(list[list.size() - 1] == 4);
	list.push_back(5);
	assert(list[list.size() - 1] == 5);
}

void testPopFront()
{
	LinkedList<int> list = { 1, 2, 3, 4, 5 };
	assert(list[0] == 1);
	list.pop_front();
	assert(list[0] == 2);
	list.pop_front();
	assert(list[0] == 3);
	list.pop_front();
	assert(list[0] == 4);
	list.pop_front();
	assert(list[0] == 5);
	list.pop_front();
	assert(list.size() == 0);
}


void testPopBack()
{
	LinkedList<int> list = { 1, 2, 3, 4, 5 };
	assert(list[list.size() - 1] == 5);
	list.pop_back();
	assert(list[list.size() - 1] == 4);
	list.pop_back();
	assert(list[list.size() - 1] == 3);
	list.pop_back();
	assert(list[list.size() - 1] == 2);
	list.pop_back();
	assert(list[list.size() - 1] == 1);
	list.pop_back();
	assert(list.size() == 0);
}

void testErase()
{
	LinkedList<int> list = { 1, 2, 3, 4, 5, 6, 7 };
	assert(list[2] == 3);
	list.erase(std::size_t(2));
	assert(list[2] != 0 && list[2] == 4);
	list.erase(std::size_t(0));
	assert(list[0] == 2);
	list.erase(7);
	assert(list[list.size() - 1] == 6);
}

void testSearch()
{
	LinkedList<int> list = { 1, 2, 3, 4, 5 };
	assert(list.search(1) == true);
	assert(list.search(3) == true);
	assert(list.search(5) == true);
	assert(list.search(8) == false);
}

void testClear()
{
	LinkedList<int> list = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 20, 34, 456, 2413, 3, 5, 542, 5234, 23543, 9911 };
	assert(list.size() != 0);
	list.clear();
	assert(list.size() == 0);
}

void testSize()
{
	LinkedList<int> list;
	assert(list.size() == 0);
	list.push_back(1);
	assert(list.size() == 1);
	list.push_back(13);
	list.push_back(37);
	assert(list.size() == 3);
	list.erase(std::size_t(2));
	assert(list.size() == 2);
	list.clear();
	assert(list.size() == 0);
}
