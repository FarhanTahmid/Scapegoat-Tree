#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED


template<class ItemType>
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
    void setKey(ItemType k);
    void setValue(ItemType v);
};

#endif //TREENODE_H_INCLUDED