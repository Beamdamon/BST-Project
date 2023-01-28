#include <iostream>
#include <cstdlib>

#include "BST.h"


using namespace std;


int main()
{

    int key = 0;
    BST myTree;

    myTree.InorderTraverse();

    //Creates the Tree
    for (int i = 0; i < 100; i++)
    {
        myTree.AddLeaf(rand());
    }

    //Prints the tree
    cout << "Printing the Tree in order\n";

    myTree.InorderTraverse();

    //Displays the menu, and gives the options to display, find a value, delete a value, and to display the minumum and maximum values.
    while (key != 5)
    {
        cout << endl << "Menu" << endl;
        cout << "1 = Display the tree" << endl;
        cout << "2 = Find a value" << endl;
        cout << "3 = Delete a value" << endl;
        cout << "4 = Display minimum and maximum" << endl;
        cout << "5 = Exit" << endl;
        cin >> key;

        switch (key)
        {
        case 1:
            cout << endl;
            cout << "Printing the Tree in order\n";
            myTree.InorderTraverse();
            cout << endl;
            break;
        case 2:
            cout << endl << "Find a number in the tree\n";
            cin >> key;
            myTree.PrintFindNode(key);
            break;
        case 3:
            cout << endl << "Input the value in the tree that you want to delete.\n";
            cin >> key;
            myTree.RemoveNode(key);
            cout << endl;
            myTree.InorderTraverse();
            cout << endl;
            break;
        case 4: 
            cout << endl << endl << "The smallest number in the tree is " << myTree.FindMinimum() << endl;
            cout << "The largest number in the tree is " << myTree.FindMaximum() << endl;
        }
    }

        return 0;
}