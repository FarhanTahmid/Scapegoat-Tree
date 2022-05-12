#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED


template<typename ItemType>
class TreeNode
{
private:
    ItemType data;
    TreeNode *key;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;

public:
    TreeNode();
    TreeNode(int key,int value);
    ItemType getKey();
    ItemType getValue();
    void setKey(int );
    void setValue(int);
    void printValue(TreeNode*);
};

#endif //TREENODE_H_INCLUDED