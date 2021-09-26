#include "BinaryTree.h"
#include <raygui.h>
#include <iostream>

BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}
BinaryTree::~BinaryTree(){}

bool BinaryTree::IsEmpty()const
{
	return m_pRoot == nullptr;
}

void BinaryTree::Insert(int a_nValue)
{

	
	//If the tree is empty, the value is inserted at the root
	TreeNode* currentNode = new TreeNode(a_nValue);
	TreeNode* parent = new TreeNode(0);
	if (IsEmpty())
	{
		m_pRoot = currentNode;
		return;
	}
	
	//Set the current node to the root
	currentNode = m_pRoot;
	
	//While the current node is not null
	while (currentNode != nullptr)
	{
			//If the value to be inserted is less than the value in the current node
		if (a_nValue < currentNode->GetData())
		{
			//if the current nodes left is not null
			if (currentNode->HasLeft())
				//Set the current node to the left child and continue
				currentNode = currentNode->GetLeft();
			else
			{
				//insert new node at left child node with value
				currentNode->SetLeft(new TreeNode(a_nValue));
				break;
			}
				
		}
			//If the value to be inserted is greater than the current node
		if (a_nValue > currentNode->GetData())
			//if the current nodes right is not null
			if (currentNode->HasRight())
			//Set the current node to the right child and continue
			currentNode = currentNode->GetRight();
			else
			{
				//insert new node at right child node with value
				currentNode->SetRight(new TreeNode(a_nValue));
				break;
			}			
			//If the value to be inserted is the same as the value in the current node
		if (a_nValue == currentNode->GetData()){
			//The value is already in the tree, so exit
			std::cout << "The value is already in the tree" << std::endl;
			break;
		}	
	}
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
//Set the current node to the root

	ppOutNode = m_pRoot;

//	While the current node is not null
	while (ppOutNode != nullptr)
	{
		//	if the search value equals the current node value,
		if (a_nSearchValue == ppOutNode->GetData())
			//return the current node and its parent
			return true;
		//otherwise
		else
		//If the search value is less than the current node
		if (a_nSearchValue < ppOutNode->GetData())
		{
			//set the parent to the current node
			ppOutParent = ppOutNode;
			//set the current node to the left child
			ppOutNode = ppOutNode->GetLeft();
		}
		else
		{
			//otherwise set the parent to the current node
			ppOutParent = ppOutNode;
			//set the current node to the right child
			ppOutNode = ppOutNode->GetRight();
			//If the loop exits, then a match was not found, so return false
		}	
	}
}
void BinaryTree::Remove(int a_nValue)
{
	//find the value in the tree, obtaining a pointer to the node and its parent
	TreeNode* searchNode = nullptr;
	TreeNode* parentNode = nullptr;
	TreeNode* replaceNode = nullptr;
	TreeNode* replaceNode_parent = nullptr;
	
	FindNode(a_nValue, searchNode, parentNode);

	if (searchNode == nullptr)
	{
		std::cout << "Are you blind, there is no node that has that value, please try again" << std::endl;
			return;
	}
	//	If the current node has a right branch, then
	if (searchNode->HasRight())
	{
		replaceNode = searchNode->GetRight();
		//	find the minimum value in the right branch by iterating down the left branch of the
		//	current node’s right child until there are no more left branch nodes
		if (replaceNode->GetLeft() == nullptr)
		{
			searchNode->SetData(replaceNode->GetData());//overite the search nodes data with replacement node
			searchNode->SetRight(replaceNode->GetRight());//link search node to replacement nodes right child
			replaceNode = nullptr;//remove replacement node
			delete replaceNode;
			return;
		}			
		while (replaceNode->GetLeft() != nullptr)
		{
			replaceNode_parent = replaceNode; //set the parent to the replacement node
			replaceNode = replaceNode->GetLeft();
		}
		//	copy the value from this minimum node to the current node
		searchNode->SetData(replaceNode->GetData());

		//	find the minimum node’s parent node(the parent of the node you are deleting)	
		//	if you are deleting the parent’s left node
		if (replaceNode_parent->GetLeft() == replaceNode)
		{
			//		set this left child of the parent to the right child of the minimum
			//		node			
			replaceNode_parent->SetLeft(replaceNode->GetRight());
		}
		//		if you are deleting the parent’s right node
		if (replaceNode_parent->GetRight() == replaceNode)
		{
			//set the right child of the parent to the minimum node’s right child
			replaceNode_parent->SetRight(replaceNode->GetRight());
			//delete the node
			replaceNode = nullptr;
			delete replaceNode;
		}
	}
			//If the current node has no right branch
			if (searchNode->GetRight() == nullptr)
			{
				//If the current node has no parent
				if (parentNode == nullptr)
				{
					//Since we are deleting the root, the roots only child becomes the root;
					m_pRoot = searchNode->GetLeft();
					//Delete the root
					searchNode = nullptr;
					delete searchNode;
					//searchNode->SetData(searchNode->GetLeft()->GetData());
					return;
				}
				//if we are deleting the parent’s left child, set the left child of the parent to the left
				//child of the current node
				if (searchNode == parentNode->GetLeft())
				{
					parentNode->SetLeft(searchNode->GetLeft());
				}			
				//If we are deleting the parent’s right child, set the right child of the parent to the left
				//child of the current node			
				if (searchNode == parentNode->GetRight())
				{
					parentNode->SetRight(searchNode->GetLeft());
				}			
			}
}
//Define public draw method
void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

//The draw() function is a recursive function that will step through the left, then the right branch of
//the tree.After drawing the branches, the function then draw the current node.

//Define private draw method
void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	horizontalSpacing /= 2;
	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80,
				horizontalSpacing, selected);
		}
		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80,
				horizontalSpacing, selected);
		}
		pNode->Draw(x, y, (selected == pNode));
	}
}
