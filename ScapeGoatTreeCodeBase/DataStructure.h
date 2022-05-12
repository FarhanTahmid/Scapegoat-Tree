#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED
#include "TreeNode.cpp"
template <typename ItemType>

class DataStructure
{
public:
    TreeNode<ItemType> *root=new TreeNode<ItemType>;
    
    DataStructure();
    void insertValue(ItemType,ItemType);
    void deleteItem();
    void searchItem();
    void printGraphically();
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
    void bfsTraversal();
    void heightOfScapeGoatTree();
    
};

#endif //DATASTRUCTURE_H_INCLUDED