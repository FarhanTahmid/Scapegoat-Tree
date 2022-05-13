#include <iostream>
#include "DataStructure.cpp"

using namespace std;

int main()
{

    int option;
    DataStructure<double> *scapeGoatTree=new DataStructure<double>();
    //DataStructure<DOUB> *scapeGoatTree=new DataStructure<int>();
    cout<<endl;
    cout<<endl;
    cout<<"Welcome to Scapegoat Tree Project!"<<endl;

    do
    {

        cout<<endl;
        cout<<endl;
        cout<<"What options you want to perform?"<<endl;
        cout<<"Select option numbers, Enter 0 to exit the program"<<endl;
        cout<<"1. Insert Values in the Tree"<<endl;
        cout<<"2. Search Node Values inside the tree"<<endl;
        cout<<"3. Delete a Value from the tree"<<endl;
        cout<<"4. Print all the values graphically"<<endl;
        cout<<"5. Perform PreOrder Traversal in the tree"<<endl;
        cout<<"6. Perform InOrder Traversal in the tree"<<endl;
        cout<<"7. Perform PostOrder Traversal in the tree"<<endl;
        cout<<"8. Perform Breadth First(BFS) Traversal"<<endl;
        cout<<"9. Find the height of the Scapegoat tree"<<endl;
        cout<<"10. Clear Screen"<<endl;
        cout<<"0. Exit Program"<<endl;
        cout<<endl;
        cout<<"Enter your choice:";
        cin>>option;
        TreeNode<double>* newNode=new TreeNode<double>();
        switch (option)
        {

        case 0:
            cout<<endl;
            cout<<"Exiting Program!"<<endl;
            break;

        case 1:
        {
            cout<<endl;
            cout<<"You are in the insert Node Operation!"<<endl;
            cout<<endl;
            cout<<"Enter how many values you want to enter in the BST:"<<endl;
            int numberOfInserts;
            cin>>numberOfInserts;
            cout<<"Enter keyValue and data: "<<endl;;
            double key;
            double value;
            while(numberOfInserts!=0){
                cout<<"[Key] [Value]: ";cin>>key>>value;
                cout<<endl;
                scapeGoatTree->insertValue(key,value);
                numberOfInserts--;
            }
            cout<<scapeGoatTree->q<<" "<<scapeGoatTree->n<<endl;
            cout<<endl;
            break;
        }
        case 2:
        {
            cout<<endl;
            cout<<"You are in the search Node Operation!"<<endl;

            break;
        }
        case 3:
        {
            cout<<endl;
            cout<<"You are in the delete Node Operation!"<<endl;

            break;
        }
        case 4:
        {
            cout<<endl;
            cout<<"Printing BST Values"<<endl;
            scapeGoatTree->printGraphically(scapeGoatTree->root,4);
            cout<<scapeGoatTree->root;
            break;
        }

        case 5:
        {
            cout<<endl;
            cout<<"The PreOrder Traversal is: "<<endl;

            break;
        }
        case 6:
        {
            cout<<endl;
            cout<<"The InOrder Traversal is: "<<endl;

            break;
        }
        case 7:
        {
            cout<<endl;
            cout<<"The PostOrder Traversal is: "<<endl;

            break;
        }
        case 8:
        {
            cout<<endl;
            cout<<"The BFS Traversal is: "<<endl;

            break;
        }
        case 9:
        {
            cout<<endl;
            cout<<"Finding the height of the tree...."<<endl;
            break;
        }
        case 10:
        {
            cout<<endl;
            system("cls");
            break;
        }
        default:
            break;
        }
    }
    while(option!=0);

}
