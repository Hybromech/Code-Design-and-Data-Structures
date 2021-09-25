#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

BST::BST()//Constructor
{
	root = NULL;
	iterator = 0;
}
BST::node* BST::CreateLeaf(int key)//Create a new leaf with specifed key
{
	node* n = new node;
	n->key = key; 
	n->left = NULL;
	n->right = NULL;

	return n;
}

void BST::AddLeaf(int key)
{
	AddLeafPrivate(key, root);//Add a leaf to tree
}
void BST::AddLeafPrivate(int key, node* Ptr)
{
	if (root == NULL)
	{
		root = CreateLeaf(key);//Set the root the new leaf if it is null
		root->parent = nullptr;//Set the roots parent to null
	}
	//place new key
	else if (key < Ptr->key)//if key is less than the current node
	{
		if (Ptr->left != NULL)
		{
			Ptr->left->parent = Ptr;//Update this nodes left childs parent
			AddLeafPrivate(key, Ptr->left);//recurse down the tree to the left until null node is found
		}
		else
		{
			Ptr->left = CreateLeaf(key);//Create a new leaf at null node
			Ptr->left->parent = Ptr;//set the parent
		}
	}
	else if (key > Ptr->key)//if key is greater than the current node
	{
		if (Ptr->right != NULL)
		{
			Ptr->right->parent = Ptr;//Update this nodes right childs parent
			AddLeafPrivate(key, Ptr->right);//recurse down the tree to the right until null node is found
		}
		else
		{
			Ptr->right = CreateLeaf(key);//Create a new leaf at null node
			Ptr->right->parent = Ptr;
		}
	}
	else
	{
		cout << "The key " << key << "has already been added to the tree\n";//the key is equal to leaf node thus it is alleady in the tree
	}

}

void BST::RemoveNode(node* node)
{
	RemoveNodePrivate(node);
}

void BST::RemoveNodePrivate(node* node)
{
	//Find out how many chidren the node has
	//delete the node depending on the case
	//repoint the other node	
	//there is no children
	if (node->left == nullptr && node->right == nullptr)
	{
		//check to see if this node is left
		if (node == node->parent->left)//compare memory address
		{
			//set the nodes parents left child to point to null then delete the node
			node->parent->left = nullptr;
			std::cout << "Node " << node->key << " has been removed" << std::endl;
			node = nullptr;
			delete node;
			return;
		}
		
		//check to see if this node is right
		if (node == node->parent->right)//compare memory address
		{
			//set the nodes parents left child to point to null then delete the node
			node->parent->right = nullptr;
			std::cout << "Node " << node->key << " has been removed" << std::endl;
			node = nullptr;
			delete node;
			return;
		}
	}
	//there is one child one the left
	if (node->left != nullptr && node->right == nullptr)
	{
		//the parent of the node points to the nodes only child.
		//delete the node
		node->parent->left = node->left;
		std::cout << "Node " << node->key << " has been removed" << std::endl;
		node = nullptr;
		delete node;
		return;
	}
	//there is one child one the right
	if (node->left == nullptr && node->right != nullptr)
	{
		//the parent of the node points to the nodes only child.
		//delete the node
		node->parent->right = node->right;
		std::cout << "Node " << node->key << " has been removed" << std::endl;
		node = nullptr;
		delete node;
		return;
	}
	//the node has two children
	if (node->left != nullptr && node->right != nullptr)
	{
		BST::node* replace = new BST::node;//create new tempory node
		replace = node->right; //discard the branch on the left, so the node to inspect is on the right branch
		//search for the lowest value that is higher than the node to be removed
		while(replace->left != nullptr)//if this is the smallest node in the branch.
		{
			replace = replace->left;
		}
		node->key = replace->key; //overwrite the nodes values
		RemoveNodePrivate(replace);//Repeat the proccess
	}
}

BST::node* BST::PreorderSearch(int key)
{
	return PreorderSearchPrivate(root,key);
}
BST::node* BST::PreorderSearchPrivate(node* currentNode, int searchKey)
{
	if (currentNode == nullptr || shouldProcess == false)//If leaf node has been reached, or the match has allready been found
	{
		shouldProcess = true;
		return search_result;
	}
			
		std::cout << "currentNode" << currentNode->key;
		if (currentNode->key == searchKey)
		{
			std::cout << "Match found" << currentNode->key << std::endl;
			shouldProcess = false;
			search_result = currentNode;
			//return search_result;
		}
	
	PreorderSearchPrivate(currentNode->left, searchKey);
	PreorderSearchPrivate(currentNode->right, searchKey);
}

int BST::Sort(int* arr)
{
	iterator = 0; //reset iterator
	SortPrivate(root, arr);
	return iterator;
}

void BST::SortPrivate(node* Ptr, int* arr)
{
	if (root != NULL)
	{
		if (Ptr->left != NULL)
		{
			SortPrivate(Ptr->left,arr);
		}
		cout << Ptr->key << " ";
		*(arr + iterator) = Ptr->key;//store value in array
		cout << "arr value is " << *(arr + iterator) << std::endl;
		iterator++;
		if (Ptr->right != NULL)
		{
			SortPrivate(Ptr->right,arr);
		}

	}
	else
	{
		cout << "The tree is empty\n";
	}
}