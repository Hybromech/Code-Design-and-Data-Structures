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
	
	void pushFront(int value)
	{
		//Create new node and set the value
		//Check if head is null, if it is then set the head to the new node
		//If it is not null then set new nodes next to the head
		node* n = new node;
		n->data = value;
		n->prev = nullptr;
		n->next = nullptr;
		
		if (head != nullptr)
		{
			head->prev = n;
			n->next = head;
			head = n;
		}	
		else
			head = n;

	}
	void pushBack(int value)
	{
		//Create new node and set the value
		//Check if tail is null, if it is then set the tail to the new node
		//If it is not null then set new nodes previous to the tail
		node* n = new node;
		n->data = value;
		n->prev = nullptr;
		n->next = nullptr;

		if (tail != nullptr)
		{
			tail->next = n;
			n->prev = tail;
			tail = n;
		}	
		else
			tail = n;

	}
	void insert(node* target_node, int value)//Insert a new item in list
	{
		node* n = new node;
		n->data = value;
		n->prev = nullptr;
		n->next = nullptr;

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
	void insert(node* target_node, node* supplied_node)//Insert a new item in list
	{
		//Update nodes previous
		if (target_node->prev != nullptr)
		{
			supplied_node->prev = target_node->prev;//set n's prev to targets prev
			target_node->prev->next = supplied_node;//set targets prevs next to n
		}

		supplied_node->next = target_node;//set n's next to target
		target_node->prev = supplied_node;//set targets prev to n

		if (supplied_node->prev == nullptr)
			head = supplied_node;
		//Update existing nodes
	}

	//Methods for removing items
	void popFront()
	{
		if (head->next != nullptr)
			head->next->prev = nullptr;
		head = head->next;
	}
	void popBack()
	{
		if (tail->prev != nullptr)
			tail->prev->next = nullptr;
		tail = tail->prev;
	}
	void erase(node* &target_node)
	{
		if (target_node != nullptr)
		{
			//Case 1 only one item in list
			if (target_node->prev == nullptr && target_node->next == nullptr)
			{
				target_node = nullptr;
				return;
			}
				//Case 2 target is the head
				if (target_node->prev == nullptr && target_node->next != nullptr)
				{
					//node* temp = target_node
					head = target_node->next;
					/*target_node->next->prev = nullptr;
					target_node = nullptr;*/
					return;
				}
				
			//Case 3 target is the tail
				if (target_node->next == nullptr && target_node->prev != nullptr)
				{
					tail = target_node->prev;
					return;
				}
			//Case 4 target is in middle
				target_node->prev->next = target_node->next;
				target_node->next->prev = target_node->prev;
				target_node = nullptr;
				delete target_node;
		}	
	}
	//Return the number of items in the list.
	int count()
	{
		node* node_to_check;
		node_to_check = head;
		int count = 0;
		while (true) //loop until a node returns null.
		{
			if (node_to_check == nullptr)
				break;//break out of loop
			else
			{
				count = count + 1;
				node_to_check = node_to_check->next;//set the node to next in list
			}
				
		}
		return count;
	}
	//Return a node specifed by index
	node* getNode(int index)
	{
		node* node_to_check;
		node_to_check = head;
		int count = 0;
		while (true) //loop until a node returns null.
		{
			if (node_to_check == nullptr)
				break;//break out of loop
			else
			{
				if (count == index)
					break;//index reached
				else
				{
					count = count + 1;
					node_to_check = node_to_check->next;//set the node to next in list
				}
			}
		}
		if (node_to_check != nullptr)
			return node_to_check;
			else return nullptr;
	}
	//Sort list
	// A utility function to swap two elements
	void swap(node* a, node* b)
	{
		//create a temp node for a
		node* temp = nullptr;
		temp->next = a->next;
		temp->prev = a->prev;
		temp->data = a->data;

		a->next = b->next;
		a->prev = b->prev;
		a->data = b->data;

		b->next = temp->next;
		b->prev = temp->prev;
		b->data = temp->data;
	}

	/* This function takes last element as pivot, places
	   the pivot element at its correct position in sorted
		array, and places all smaller (smaller than pivot)
	   to left of pivot and all greater elements to right
	   of pivot */
	node* partition(node* tail, node* head)//low is the tail
	{
		int pivot = tail->data;    // pivot
		node* i = head;  // Index of smaller element

		for (node* j = head; j == tail ; j = j->next)//Loop until the current nodes is equal to high.
		{
			// If current element is smaller than or
			// equal to pivot
			if (j-> data <= pivot)
			{
				i = i->next; //increment index of smaller element
				swap(i, j); //swap elements
			}
		}

		insert(i->next, tail);//put the pivot in correct position
		return head;//return the pivot or partitioning index.
	}

	/* The main function that implements QuickSort
	 arr[] --> Array to be sorted,
	  low  --> Starting index,
	  high  --> Ending index */
	void quickSort(node* tail, node* head)
	{
		if (tail->prev != nullptr)
		{
			/* pi is partitioning index, arr[p] is now
			   at right place */
			node* pi = partition(tail, head);//Get the partition index
			//Divide and conquer
			// Separately sort elements before
			// partition and after partition
			quickSort(tail, pi->prev);
			quickSort(pi->next, head);
		}
	}

	/* Function to print an array */
	void printArray(int arr[], int size)
	{
		int i;
		for (i = 0; i < size; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	
	void display_list()
	{
		node* node_to_show;
		node_to_show = head;
											
		while (node_to_show != nullptr)
		{
			std::cout << "node " << node_to_show->data << std::endl;
			node_to_show = node_to_show->next;
		}
	}
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
	linked_list.pushFront(133);
	linked_list.pushBack(797);
	linked_list.pushBack(65);
	linked_list.quickSort(linked_list.tail, linked_list.head);
	std::cout << "list size is " << linked_list.count() << std::endl;
	std::cout << "head" << linked_list.head->data;
	std::cout << "The data in the 1st item of the list is" << linked_list.getNode(0)->data;
	linked_list.display_list();

	return 0;
}