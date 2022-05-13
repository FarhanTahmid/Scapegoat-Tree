#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED



class TreeNode
{
private:
    double data;
    int key;
    

public:
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode();
    TreeNode(int,double);
    int getKey();
    double getValue();
    void setKey(int);
    void setValue(double);
    //void printValue(TreeNode*);
};

#endif //TREENODE_H_INCLUDED