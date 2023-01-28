#include <iostream>
#include <cstdlib>

#include "BST.h"


using namespace std;


int main()
{

    int key;
    BST myTree;

        myTree.InorderTraverse();

        for (int i = 0; i < 100; i++)
        {
            myTree.AddLeaf(rand());
        }

    
        cout << "Printing the Tree in order\n";

        myTree.InorderTraverse();

        cout << endl << endl << "The smallest number in the tree is " << myTree.FindMinimum() << endl;
        cout << "The largest number in the tree is " << myTree.FindMaximum() << endl;

        cout << endl << "Find a number in the tree\n";
        cin >> key;
        myTree.PrintFindNode(key);


    return 0;
}