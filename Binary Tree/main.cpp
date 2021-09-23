#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

int main() 
{
    int* arr;
    int TreeKeys[20] = { 20,96,5,23,54,67,3,2,9,7,32,12,64,21,13,96,123,500,120,160 };
    arr = TreeKeys;
    BST myTree;
     
    cout << "Printing the tree in order\nBefore adding numbers\n";

    myTree.Sort(arr);

    for (int i = 0; i < 20; i++)
    {
        myTree.AddLeaf(TreeKeys[i]);
    }
    
    cout << "Printing the tree in order\nAfter adding numbers\n" << std::endl;

    int length = myTree.Sort(arr);

    cout << "\nPrinting elements in array" << std::endl;
    
    for (int i = 0; i < length; i++)
    {
        std::cout << TreeKeys[i] << " ";
    }
    //Search for a value
    

    //remove a node

    myTree.search_result = myTree.PreorderSearch(21);
    myTree.RemoveNode(myTree.search_result);//Search for node and then remove it.
    
    myTree.search_result = myTree.PreorderSearch(23);
    myTree.RemoveNode(myTree.search_result);//Search for node and then remove it.
    
    
    myTree.Sort(arr);
	return 0;
}
