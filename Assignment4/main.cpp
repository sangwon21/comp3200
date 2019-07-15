#include <cassert>
#include "TreeNode.h"
#include "BinarySearchTree.h"
#include <iostream>

using namespace assignment4;
using namespace std;

int main()
{
	TreeNode<int> n(std::make_unique<int>(2));

	std::shared_ptr<TreeNode<int>> parent = std::make_shared<TreeNode<int>>(std::make_unique<int>(5));
	TreeNode<int> n2(parent, std::make_unique<int>(2));

	cout << "The End of the Test" << endl;
	cin.get();
	return 0;
}