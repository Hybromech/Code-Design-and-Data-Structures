#pragma once
class BST
{
private:

	struct node
	{
		int key;
		node* left;
		node* right;
		node* parent;
	};

	node* root;
	node* search_node;
	//Adds a leaf given the specifed node
	void AddLeafPrivate(int key, node* Ptr);
	//Removes a node from the tree.
	void RemoveNodePrivate(node* node);
	//Rewrites to the array the values in the tree in order
	void SortPrivate(node*,int* arr);
	//Searches the tree for a given key
	node* PreorderSearchPrivate(node* currentNode, int searchKey);

public:

	BST(); 
	//Creates a new leaf with specifed key
	node* CreateLeaf(int key);
	//Calls AddLeafPrivate
	void AddLeaf(int key);
	void RemoveNode(node* node);
	node* PreorderSearch(int searchKey);
	node* search_result;
	int Sort(int* arr);
	int iterator = 0;
	bool shouldProcess = true;
};