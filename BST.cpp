#include <iostream>
#include <cstdlib>
#include <Chrono>

#include "BST.h"

using namespace std;
using namespace std::chrono;

BST::BST()
{
	root = NULL;
}

// Creates a new node
BST::node* BST::CreateLeaf(int key)
{
	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;

	return n;
}

// Adds a new leaf to the tree by recursively going through the tree to see if the key value is < > or = to the current value being looked at
void BST::AddLeaf(int key)
{
	AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* Ptr)
{
	if (root == NULL)
	{
		root = CreateLeaf(key);
	}
	else if (key < Ptr->key)
	{
		if (Ptr->left != NULL)
		{
			AddLeafPrivate(key, Ptr->left);
		}
		else
		{
			Ptr->left = CreateLeaf(key);
		}
	}
	else if (key > Ptr->key)
	{
		if (Ptr->right != NULL)
		{
			AddLeafPrivate(key, Ptr->right);
		}
		else
		{
			Ptr->right = CreateLeaf(key);
		}
	}
	else
	{
		cout << "The key " << key << " Is already in the tree\n";
	}
}

// Recursively goes through the tree to put the values of the tree in numerical order
void BST::InorderTraverse()
{
	InorderTraversePrivate(root);
}

void BST::InorderTraversePrivate(node* Ptr)
{
	if (root != NULL)
	{
		if (Ptr->left != NULL)
		{
			InorderTraversePrivate(Ptr->left);
		}
		
		cout << Ptr->key << " ";

		if (Ptr->right != NULL)
		{
			InorderTraversePrivate(Ptr->right);
		}
	}
	else
	{
		cout << "The tree is empty.\n";
	}
}

// Recursively goes through the tree until the ptr->key == key
BST::node* BST::FindNode(int key)
{
	return FindNodePrivate(key, root);
}

BST::node* BST::FindNodePrivate(int key, node* Ptr)
{
	if (Ptr != NULL)
	{
		if (Ptr->key == key)
		{
			return Ptr;
		}
		else 
		{
			if (key < Ptr->key)
			{
				return FindNodePrivate(key, Ptr->left);
			}
			else
			{
				return FindNodePrivate(key, Ptr->right);
			}
		}
	}
	else
	{
		return NULL;
	}
}

//Prints the node found from the FindNode Function.
void BST::PrintFindNode(int key)
{
	node* Ptr = FindNode(key);

	if (Ptr != NULL)
	{
		cout << Ptr->key << " Is in the tree" << endl;
	}
	else
	{
		cout << "Key " << key << " is not in the tree.\n";
	}
}

//Finds the minimum value in the tree by recursively moving to the very far left of the tree.
int BST::FindMinimum()
{
	return FindMinimumPrivate(root);
}

int BST::FindMinimumPrivate(node* Ptr)
{
	if (root == NULL)
	{
		cout << "The tree is empty\n";
		return -10;
	}
	else
	{
		if (Ptr->left != NULL)
		{
			return FindMinimumPrivate(Ptr->left);
		}
		else
		{
			return Ptr->key;
		}
	}
}

//Finds the maximum value in the tree by recursively moving to the very far right of the tree.
int BST::FindMaximum()
{
	return FindMaximumPrivate(root);
}

int BST::FindMaximumPrivate(node* Ptr)
{
	if (root == NULL)
	{
		cout << "The tree is empty\n";
		return -10;
	}
	else
	{
		if (Ptr->right != NULL)
		{
			return FindMaximumPrivate(Ptr->right);
		}
		else
		{
			return Ptr->key;
		}
	}
}

//Removal functions below finds the match, deletes it, then reconstructs the tree.

void BST::RemoveNode(int key)
{
	return RemoveNodePrivate(key, root);

}

void BST::RemoveNodePrivate(int key, node* parent)
{
	if (root != NULL)
	{
		if (root->key == key)
		{
			RemoveRootMatch();
		}
		else
		{
			if (key < parent->key && parent->left != NULL)
			{
				parent->left->key == key ?
					RemoveMatch(parent, parent->left, true) :
					RemoveNodePrivate(key, parent->left);
			}
			else if (key > parent->key && parent->right != NULL)
			{
				parent->right->key == key ?
					RemoveMatch(parent, parent->right, false) :
					RemoveNodePrivate(key, parent->right);
			}
			else
			{
				cout << "The key " << key << " was not found in the tree\n";
			}
		}
	}
	else
	{
		cout << "The tree is empty\n";
	}
}

void BST::RemoveRootMatch()
{
	if (root != NULL)
	{
		node* delPtr = root;
		int rootKey = root->key;
		int smallestInRightSubtree;

		// 0 Children
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete delPtr;
		}

		//  1 Child
		else if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
			cout << "The root node with key " << rootKey << " was deleted. " << endl;
		}
		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
			cout << "The root node with key " << rootKey << " was deleted. " << endl;
		}

		// 2 Children
		else
		{
			smallestInRightSubtree = FindMinimumPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubtree, root);
			root->key = smallestInRightSubtree;
			cout << "The root key containing key " << rootKey << " was overwritten with key " << root->key << endl;
		}
	}
	else
	{
		cout << "Can not remove root. The tree is empty.\n";
	}
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
	if (root != NULL)
	{
		node* delPtr;
		int matchKey = match->key;
		int smallestInRightSubtree;

		// 0 Children
		if (match->left == NULL && match->right == NULL)
		{
			delPtr = match;
			left == true ? parent->left = NULL : parent->right = NULL;
			delete delPtr;
			cout << " The node containing key " << matchKey << " was removed \n";
		}
		// 1 Child
		else if (match->left == NULL && match->right != NULL)
		{
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			delPtr = match;
			delete delPtr;
			cout << " The node containing key " << matchKey << " was removed \n";
		}
		else if (match->left != NULL && match->right == NULL)
		{
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			delPtr = match;
			delete delPtr;
			cout << " The node containing key " << matchKey << " was removed \n";
		}
		// 2 Children
		else
		{
			smallestInRightSubtree = FindMinimumPrivate(match->right);
			RemoveNodePrivate(smallestInRightSubtree, match);
			match->key = smallestInRightSubtree;
		}
	}
	else
	{
		cout << " The tree is empty. \n";
	}
}