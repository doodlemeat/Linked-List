#include <iostream>

#include "LinkedList.h"

void checkLetter(const LinkedList<std::string>& list, const std::string& v)
{
	if (list.search(v))
	{
		std::cout << "Letter " << v.c_str() << " was found in list" << std::endl;
	}
	else
	{
		std::cout << "Letter " << v.c_str() << " was not found in list" << std::endl;
	}
}

void printList(const LinkedList<std::string>& list)
{
	std::cout << "Linked List with " << list.size() << " elements contained" << std::endl;
	Node<std::string>* node = list.getHead();

	int index = 0;
	while (node != nullptr)
	{
		std::cout << "[" << index << "] " << node->m_data.c_str() << std::endl;
		node = node->m_next;
		++index;
	}
}

int main()
{
	LinkedList<std::string> letters;
	
	letters.push_back("l");
	letters.push_back("e");
	letters.push_back("m");
	letters.push_back("e");
	letters.push_back("a");
	letters.push_back("t");

	letters.push_front("d");
	letters.push_front("o");
	letters.push_front("o");
	letters.push_front("d");

	printList(letters);

	letters.pop_back();
	letters.pop_back();

	letters.pop_front();
	letters.pop_front();

	printList(letters);

	letters.push_back("a");
	letters.push_back("t");
	letters.push_front("o");
	letters.push_front("d");

	printList(letters);

	checkLetter(letters, "u");
	checkLetter(letters, "m");

	letters.erase("t");
	letters.erase("d");

	printList(letters);

	letters.push_back("t");
	letters.push_front("d");

	printList(letters);

	std::cout << "Current size of linked list is " << letters.size() << std::endl;
	letters.clear();
	printList(letters);

	return 0;
}