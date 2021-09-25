#pragma once
#include "TreeNode.h"

	class BinaryTree
	{
	public:
		BinaryTree();
		~BinaryTree();

		bool IsEmpty() const;
		void Insert(int a_nValue);
		void Remove(int a_nValue);
		TreeNode* Find(int a_nValue);

		void PrintOrdered();
		void PrintUnordered();

		void Draw(TreeNode* selected = nullptr); //creates new tree node when function is called

	private:
		
		//Find the node with the specifed value.
		bool FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent);

		//Used to recurse through the nodes in value order and print their values.
		void PrintOrderedRecurse(TreeNode*);
		void PrintUnorderedRecurse(TreeNode*);


		void Draw(TreeNode*, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);

		//The root node of the tree
		TreeNode* m_pRoot;
	};

