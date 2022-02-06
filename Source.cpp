#include<iostream>
#include"BinaryTree.h"
#include"FIFO.h"
#include"list.h"
using namespace BST;
using namespace FIFO;
using namespace list;

int main()
{
	Tree<int> tree;

	tree.add(34);
	tree.add(52);
	tree.add(36);
	tree.add(99);
	tree.add(12);

	tree.print();
}