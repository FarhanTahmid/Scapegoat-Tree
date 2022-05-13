#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED
#include "TreeNode.cpp"
#include <list>

class DataStructure
{
public:
    TreeNode *root=new TreeNode();
    int n; //number of items in the data structure
    int q=0; //overestimate of n
    DataStructure();
    static int const log32(int);
    bool isEmpty();
    int size1(TreeNode*);
    int sizeofTree();
    int findDepthWhileAdding(TreeNode*);
    TreeNode* buildBalancedTree(TreeNode**,int,int);
    int storeInArray(TreeNode*,TreeNode*[],int);
    void rebuildTree(TreeNode*);
    bool insertValue(int,double);
    void searchItem();
    void printGraphically(TreeNode*,int);
    void preOrderTraversal(TreeNode*);
    void inOrderTraversal(TreeNode*);
    void postOrderTraversal(TreeNode*);
    void breadthFirstTraversal(TreeNode*);
    int heightOfScapeGoatTree(TreeNode*);
    void printLevel(TreeNode*,int);
    TreeNode *searchValue(double);
    TreeNode *deleteNode(TreeNode*,double);
    TreeNode *minValueNode(TreeNode*);
};

#endif //DATASTRUCTURE_H_INCLUDED
