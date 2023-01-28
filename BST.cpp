#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

BST::BST()
{
	root = NULL;
}

BST::node* BST::CreateLeaf(int key)
{
	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;

	return n;
}

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