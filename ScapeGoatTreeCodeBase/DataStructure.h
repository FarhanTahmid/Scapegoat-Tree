#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED
#include "TreeNode.cpp"
template <class ItemType>
class DataStructure
{
private:
    ItemType data;
    TreeNode *root;

public:
    TreeNode();
    void insertValue();
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