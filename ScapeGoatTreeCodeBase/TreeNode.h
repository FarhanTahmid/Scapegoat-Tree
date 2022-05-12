#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED


template<typename ItemType>
class TreeNode
{
private:
    ItemType data;
    ItemType key;
    

public:
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode();
    TreeNode(ItemType,ItemType);
    ItemType getKey();
    ItemType getValue();
    void setKey(ItemType);
    void setValue(ItemType);
    void printValue(TreeNode*);
};

#endif //TREENODE_H_INCLUDED