#include <iostream>
#include "DataStructure.cpp"

using namespace std;

int main()
{

    int option;
    DataStructure *scapeGoatTree = new DataStructure();
    // DataStructure<DOUB> *scapeGoatTree=new DataStructure<int>();
    cout << endl;
    cout << endl;
    cout << "Welcome to Scapegoat Tree Project!" << endl;

    do
    {

        cout << endl;
        cout << endl;
        cout << "What options you want to perform?" << endl;
        cout << "Select option numbers, Enter 0 to exit the program" << endl;
        cout << "1. Insert Values in the Tree" << endl;
        cout << "2. Search Node Values inside the tree" << endl;
        cout << "3. Delete a Value from the tree" << endl;
        cout << "4. Print all the values graphically" << endl;
        cout << "5. Perform PreOrder Traversal in the tree" << endl;
        cout << "6. Perform InOrder Traversal in the tree" << endl;
        cout << "7. Perform PostOrder Traversal in the tree" << endl;
        cout << "8. Perform Breadth First(BFS) Traversal" << endl;
        cout << "9. Find the height of the Scapegoat tree" << endl;
        cout << "10. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;
        cout << endl;
        cout << "Enter your choice:";
        cin >> option;
        TreeNode *newNode = new TreeNode();
        int heightOfScapeGoatTree = 0;
        switch (option)
        {

        case 0:
            cout << endl;
            cout << "Exiting Program!" << endl;
            break;

        case 1:
        {
            cout << endl;
            cout << "You are in the insert Node Operation!" << endl;
            cout << endl;
            cout << "Enter how many values you want to enter in the BST:" << endl;
            int numberOfInserts;
            cin >> numberOfInserts;
            cout << "Enter keyValue and data: " << endl;
            ;
            double key;
            double value;
            while (numberOfInserts != 0)
            {
                cout << "[Key] [Value]: ";
                cin >> key >> value;
                cout << endl;
                scapeGoatTree->insertValue(key, value);
                numberOfInserts--;
            }
            // cout<<scapeGoatTree->q<<" "<<scapeGoatTree->n<<endl;
            cout << endl;
            break;
        }
        case 2:
        {
            cout << endl;
            cout << "You are in the search Node Operation!" << endl;
            int searchValue;
            cout << "Enter a value to search: ";
            cin >> searchValue;
            cout << endl;
            newNode = scapeGoatTree->searchValue(searchValue);
            if (scapeGoatTree->isEmpty())
            {
                cout << "Tree is Empty" << endl;
            }
            else
            {
                if (newNode != NULL)
                {
                    cout << "Found the value " << searchValue << " in the tree" << endl;
                }
                else
                {
                    cout << "Couldn't find the valeu " << searchValue << " int the tree" << endl;
                }
            }
            break;
        }
        case 3:
        {
            cout << endl;
            cout << "You are in the delete Node Operation!" << endl;
            if (scapeGoatTree->isEmpty())
            {
                cout << "The tree is empty, can not perform Delete operation!" << endl;
            }
            else
            {
                double valueToDelete;
                cin >> valueToDelete;
                newNode = scapeGoatTree->searchValue(valueToDelete);
                if (newNode != NULL)
                {
                    TreeNode *newNode2 = new TreeNode();
                    newNode2 = scapeGoatTree->deleteNode(scapeGoatTree->root, valueToDelete);
                    if (newNode2 != NULL)
                    {
                        cout << "The value " << valueToDelete << " was deleted from the tree" << endl;
                    }
                    else
                    {
                        cout << "The value " << valueToDelete << " was deleted from the tree" << endl;
                    }
                }
                else{
                    cout << "Value not present in the tree" << endl;
                }
            }

            break;
        }
        case 4:
        {
            cout << endl;
            cout << "Printing BST Values" << endl;
            scapeGoatTree->printGraphically(scapeGoatTree->root, 4);
            // cout<<scapeGoatTree->root;1
            
            break;
        }

        case 5:
        {
            cout << endl;
            cout << "The PreOrder Traversal is: " << endl;
            scapeGoatTree->preOrderTraversal(scapeGoatTree->root);
            break;
        }
        case 6:
        {
            cout << endl;
            cout << "The InOrder Traversal is: " << endl;
            scapeGoatTree->inOrderTraversal(scapeGoatTree->root);
            break;
        }
        case 7:
        {
            cout << endl;
            cout << "The PostOrder Traversal is: " << endl;
            scapeGoatTree->postOrderTraversal(scapeGoatTree->root);
            break;
        }
        case 8:
        {
            cout << endl;
            cout << "The BFS Traversal is: " << endl;
            scapeGoatTree->breadthFirstTraversal(scapeGoatTree->root);
            break;
        }
        case 9:
        {
            cout << endl;
            cout << "Finding the height of the tree...." << endl;
            heightOfScapeGoatTree = scapeGoatTree->heightOfScapeGoatTree(scapeGoatTree->root);
            cout << "Height of tree is: " << heightOfScapeGoatTree << endl;
            break;
        }
        case 10:
        {
            cout << endl;
            system("cls");
            break;
        }
        default:
            break;
        }
    } while (option != 0);
}
