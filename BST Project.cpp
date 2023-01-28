#include <iostream>
#include <cstdlib>

#include "BST.h"


using namespace std;


int main()
{

    int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
    BST myTree;

        myTree.InorderTraverse();

        for (int i = 0; i < 100; i++)
        {
            myTree.AddLeaf(rand());
        }

    
        cout << "Printing the Tree in order\n";

        myTree.InorderTraverse();

    return 0;
}