#include <cassert>
#include "TreeNode.h"
#include "BinarySearchTree.h"
#include <iostream>

using namespace assignment4;
using namespace std;

int main()
{
	BinarySearchTree<int> tree;

	tree.Insert(std::make_unique<int>(10));
	tree.Insert(std::make_unique<int>(15));
	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(4));
	tree.Insert(std::make_unique<int>(19));
	tree.Insert(std::make_unique<int>(20));
	tree.Insert(std::make_unique<int>(17));
	tree.Insert(std::make_unique<int>(12));

	std::vector<int> v = tree.TraverseInOrder(tree.GetRootNode().lock());

	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << i << " is : " << v[i] << endl;
	}

	cout << tree.Delete(-1) << endl;
	cout << tree.Delete(15) << endl;

	v = tree.TraverseInOrder(tree.GetRootNode().lock());

	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << i << " is : " << v[i] << endl;
	}

	cout << "The End of the Test" << endl;
	cin.get();
	return 0;
}