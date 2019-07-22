#include <cassert>
#include "DoublyLinkedList.h"
#include "Node.h"
#include <iostream>

using namespace lab10;
using namespace std;
int main()
{
	DoublyLinkedList<int> list;

	list.Insert(std::make_unique<int>(1));
	list.Insert(std::make_unique<int>(2));
	list.Insert(std::make_unique<int>(3));
	list.Insert(std::make_unique<int>(4));
	list.Insert(std::make_unique<int>(5));
	list.Insert(std::make_unique<int>(6));
	list.Insert(std::make_unique<int>(7)); // 6

	std::shared_ptr<Node<int>> node = list[2];
	assert(*node->Data == 3);

	list.Insert(std::make_unique<int>(10), 2);
	list.Insert(std::make_unique<int>(11), 0);
	node = list[0];
	cout << *node->Data << endl;
	assert(*node->Data == 11);
	
	list.Insert(std::make_unique<int>(70), 8);
	node = list[9];
	assert(*node->Data == 70);

	return 0;
}