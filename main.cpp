// A C++ program to sort a linked list using Quicksort
//#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
using namespace std;

/* a node of the doubly linked list */
class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

/* A utility function to swap two elements */
void swap(int* a, int* b)
{
    int t = *a; *a = *b; *b = t;
}

// A utility function to find
// last node of linked list
Node* lastNode(Node* root)
{
    while (root && root->next)
        root = root->next;
    return root;
}
int node_count(Node* root)
{
    if (root == nullptr)//this means the list is empty
        return 0;
    int count = 1;
    while (root && root->next)
    {
        root = root->next;
        count++;
    }
    return count;
}

/* Considers last element as pivot,
places the pivot element at its
correct position in sorted array,
and places all smaller (smaller than
pivot) to left of pivot and all greater
elements to right of pivot */
Node* partition(Node* l, Node* h)
{
    // set pivot as h element
    int x = h->data;

    // similar to i = l-1 for array implementation
    Node* i = l->prev;

    // Similar to "for (int j = l; j <= h- 1; j++)"
    for (Node* j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            // Similar to i++ for array
            i = (i == nullptr) ? l : i->next;

            swap(&(i->data), &(j->data));
        }
    }
    i = (i == nullptr) ? l : i->next; // Similar to i++
    swap(&(i->data), &(h->data));
    return i;
}

/* A recursive implementation
of quicksort for linked list */
void _quickSort(Node* l, Node* h)
{
    if (h != nullptr && l != h && l != h->next)
    {
        Node* p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}

// The main function to sort a linked list.
// It mainly calls _quickSort()
void quickSort(Node* head)
{
    // Find last node
    Node* h = lastNode(head);

    // Call the recursive QuickSort
    _quickSort(head, h);
}

// A utility function to print contents of arr
void printList(Node* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/* Function to insert a node at an arbitary position in the
    Doubly Linked List */
void insert(Node* head_ref, int index, int new_data)
{
    Node* new_node = new Node; /* allocate node */
    Node* temp = head_ref;//set temp testing node to head
    new_node->data = new_data;
    
    int count = 0;
    while (count != index && temp != nullptr)
    {
        temp = temp->next;
        count++;
    }
    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->next->prev = new_node;
}

/* Function to remove a node at an arbitary position in the
    Doubly Linked List */
void Remove(Node** head_ref, int index)
{
    Node* head = *head_ref;
    Node* temp = *head_ref;//set temp testing node to head

    int count = 0;
    while (count != index && temp != nullptr)
    {
        temp = temp->next;
        count++;
    }
    //remove temp and relink its next and previous
    //check to see if temps next and previous has a valid node
    if (temp == *head_ref)
    {
        head = temp->next;
        head->prev = nullptr;
        delete head->prev;
    }
    else if (temp == lastNode(head))
    {
        temp = temp->prev;
        temp->next = nullptr;
        delete temp->next;
    }
    else //the node is somewhere in the middle
    {
        //relink the list
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        //delete temp
        temp = nullptr;
        delete temp;
    }   
    *head_ref = head; 
}
void push_front(Node** head_ref, int new_data)
{
    Node* new_node = new Node; /* allocate node */
    new_node->data = new_data;

    /* since we are adding at the
    beginning, prev is always NULL */
    new_node->prev = nullptr;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* change prev of head node to new node */
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
void push_back(Node** head_ref, int new_data)
{
    Node* new_node = new Node; /* allocate node */
    new_node->data = new_data;

    /* since we are adding at the
    end, prev will be the last node*/
    Node* second_last = lastNode(*head_ref);
    second_last->next = new_node;
    new_node->prev = second_last;
    
    /* the last nodes next is null */
    new_node->next = nullptr;
}

//remove a node at the front of the list
void pop_front(Node** head_ref)
{
    (*head_ref) = (*head_ref)->next;
    (*head_ref)->prev = nullptr;
}
//remove a node from the back of the list
void pop_back(Node** head_ref)
{
    lastNode(*head_ref)->prev->next = nullptr;
}

/* Driver code */
int main()
{
    Node* a = nullptr;
    cout << "the linked list size is " << node_count(a) << endl;
    push_front(&a, 5);
    push_front(&a, 20);
    push_front(&a, 4);
    push_front(&a, 3);
    push_front(&a, 30);
    push_back(&a, 159);
    insert(a, 0, 88);//insert node at index 0
    printList(a);
    Remove(&a, 0);
    printList(a);
    //pop_front(&a);
    //pop_front(&a);
    //pop_back(&a);
    //pop_back(&a);
    cout << "the linked list size is " << node_count(a) << endl;
    cout << "Linked List before sorting \n";
    printList(a);

    quickSort(a);

    cout << "Linked List after sorting \n";
    printList(a);

    return 0;
}
