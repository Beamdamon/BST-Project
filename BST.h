class BST 
{

private:
	
	struct node
	{
		int key;
		node* left;
		node* right;
	};

	node* root;
	
	void AddLeafPrivate(int key, node* Ptr);
	void InorderTraversePrivate(node* Ptr);
	node* FindNodePrivate(int key, node* Ptr);
	int FindMinimumPrivate(node* Ptr);
	int FindMaximumPrivate(node* Ptr);
	void RemoveNodePrivate(int key, node* parent);
	void RemoveRootMatch();
	void RemoveMatch(node* parent, node* match, bool left);

public:

	BST();
	node* CreateLeaf(int key);
	void AddLeaf(int key);
	void InorderTraverse();
	node* FindNode(int key);
	void PrintFindNode(int key);
	int FindMinimum();
	int FindMaximum();
	void RemoveNode(int key);
};
