#include <cstdlib>
#include <iostream>

using namespace std;

//What a node object consists of
class node {
public: int data;//Data to be stored
	  node* next;//Reference to the next node.
	  node* prev;//Reference to the previous node.
};

class Linked_List
{
public:
	node* head;//Reference to the start of the list
	node* tail;//Reference to the end of the list
	//Methods for adding items
	void Get_node();
	void pushFront(int value);
	void pushBack(int value);
	void insert(node* target_node, int value)//Insert a new item in list
	{
		node* n = new node;
		n->data = value;
		n->prev = nullptr;

		//Update nodes previous
		if (target_node->prev != nullptr)
		{
			n->prev = target_node->prev;//set n's prev to targets prev
			target_node->prev->next = n;//set targets prevs next to n
		}
		

		n->next = target_node;//set n's next to target
		target_node->prev = n;//set targets prev to n

		if (n->prev == nullptr)
			head = n;

		//Update existing nodes

	}

	//Methods for removing items
	void popFront();
	void popBack();
	void erase(node);
	void remove(int value);
};

int main(int argc, char** argv){

	Linked_List linked_list;
	
	node* node1;

	node1 = new node; 
	node1->data = 1;
	node1->prev = nullptr;
	linked_list.head = node1;
	linked_list.tail = node1;

	linked_list.insert(node1,4); //insert another node at new_node
	linked_list.insert(node1, 8); //insert another node at new_node

	//Display nodes
	std::cout << "Node3 contains " << node1->data << std::endl;
	std::cout << "Node2 contains " << node1->prev->data << std::endl;
	std::cout << "Node1 contains " << node1->prev->prev->data << std::endl;
	std::cout << "the head contains " << linked_list.head->data << std::endl;
	return 0;
}