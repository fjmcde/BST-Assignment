// All function prototypes and the functionality of the constructor were written by Professor Bonnie Bell.
// I wrote the functionality of each function given the data abstraction.
// This is NOT the standard implementation of a BST, though it did force us to work with less-than
// favorable abstraction in order implement the solution.

#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int t_data, Node* t_left, Node* t_right)
{
	data = t_data;
	left = t_left;
	right = t_right;
}

void Node::insert(int new_data)
{
	// insert left child
	if(new_data < data)
	{
		if (left == nullptr)
		{
			left = new Node(new_data);
		}
		else
		{
			left->insert(new_data);
		}
	}
	// insert right child
	else
	{
		if (right == nullptr)
		{
			right = new Node(new_data);
		}
		else
		{
			right->insert(new_data);
		}
	}
}

bool Node::isLeaf()
{
	/***********************************************************
	** A node is considered a leaf when it has no child nodes **
	************************************************************/

	// nice and concise!
	return (left == nullptr && right == nullptr);
}

uint32_t Node::height()
{
	/******************************************************************************
	** The height of a BST is based on the number of edges on the longest branch **
	** from the root                                                             **
	******************************************************************************/

	int leftHeight = 0;
	int rightHeight = 0;

	// base case; branch ends here
	if(this->isLeaf())
	{
		return 0;
	}

	// recursively find the height of the left and right paths for all nodes.
	if(left != nullptr)
	{
		leftHeight = left->height();
	}
	if(right != nullptr)
	{
		rightHeight = right->height();
	}
	
	// return the height of the largest path
	if (leftHeight > rightHeight)
	{
		return leftHeight + 1;
	}
	else
	{
		return rightHeight + 1;
	}
}

bool Node::isFull()
{
	/***********************************************************************
	** A BST is considered full if each node meets at least one condtion: **
	** ------------------------------------------------------------------ **
	** A) node is NULL                                                    **
	** B) node has zero children (is a leaf)                              **
	** C) node has two child nodes                                        **
	***********************************************************************/
	
	// required for base-case (only way I could work it without compiler warnings!)
	Node* root = new Node(data);

	// A) Node is null; base case
	if(root == nullptr)
	{
		return true;
	}

	// B) Node is a leaf
	if(this->isLeaf())
	{
		return true;
	}

	// C) Node has two children
	if(left != nullptr && right != nullptr)
	{
		return left->isFull() && right->isFull();
	}

	// None of the criteria have been met for at least one node
	return false;
}

uint32_t Node::countNodes()
{
	/***********************************************************************************
	** When counting nodes we only need check for a few things:                       **
	** ------------------------------------------------------------------------------ **
	** A) If the node is a leaf, the branch ends here (doubles as base case)          **
	** B) If either the left or right nodes are nullptrs, only count the valid branch **
	** C) If both branches are valid, count both                                      **
	***********************************************************************************/

	// A) Leaf node; branch ends at this node (also base case)
	if(this->isLeaf())
	{
		return 1;
	}
	// B) only left branch is valid; count the left branch recusrively
	else if(left == nullptr)
	{
		return right->countNodes() + 1;
	}
	// B) Only right branch is valid; count the right branch recursively
	else if(right == nullptr)
	{
		return left->countNodes() + 1;
	}
	// C) Count both branches recursively
	else
	{
		return 1 + (left->countNodes() + right->countNodes());
	}
}