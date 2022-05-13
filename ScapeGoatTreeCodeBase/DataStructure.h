#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED
#include "TreeNode.cpp"
#include <list>
template <typename ItemType>

class DataStructure
{
public:
    TreeNode<ItemType> *root=new TreeNode<ItemType>;
    int n; //number of items in the data structure
    int q; //overestimate of n
    DataStructure();
    static int const log32(int);
    bool isEmpty();
    int size(TreeNode<ItemType>&);
    int sizeofTree();
    int findDepthWhileAdding(TreeNode<ItemType>&);
    TreeNode<ItemType>* buildBalancedTree(TreeNode<ItemType>&&,int,int); 
    int storeInArray(TreeNode<ItemType>&,TreeNode<ItemType[]>&,int);
    void rebuildTree(TreeNode<ItemType>&);
    bool insertValue(ItemType,ItemType);
    void deleteItem();
    void searchItem();
    void printGraphically(TreeNode<ItemType>&,int);
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
    void bfsTraversal();
    void heightOfScapeGoatTree();
    
};

#endif //DATASTRUCTURE_H_INCLUDED