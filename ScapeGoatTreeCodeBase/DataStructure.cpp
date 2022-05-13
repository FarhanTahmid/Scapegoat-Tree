#include<iostream>
#include "DataStructure.h"
#include<list>
#include<math.h>
#define SPACE 10
using namespace std;


DataStructure  ::DataStructure(){
    root=NULL;
    n=0;
}

 
bool
DataStructure  ::isEmpty(){
    return root==NULL;
}
 
int //count number of nodes of a parent
DataStructure  ::size1(TreeNode  * tree){
    if(tree==NULL){
        return 0;
    }else{
        int size=1;
        size+=size1(tree->left);
        size+=size1(tree->right);
        return size;
    }
}

 
int
DataStructure  ::sizeofTree(){
    return n;
}

 
const int
DataStructure::log32(int number){
    double const log23=2.4663034623764317;
    
    return (int)floor(log23*log(number));
}
 
int DataStructure::findDepthWhileAdding(TreeNode* node){
    TreeNode *temp = root;
            if (temp == NULL)
            {
                root = node;
                n++;
                q++;
                return 0;
            }
            bool complete = false;
            int depth=0;
            do
            {
                if (node->getValue() < temp->getValue())
                {
                    if (temp->left == NULL)
                    {
                        temp->left = node;
                        node->parent = temp;
                        complete = true;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else if (node->getValue() > temp->getValue())
                {
                    if (temp->right == NULL)
                    {
                        temp->right = node;
                        node->parent = temp;
                        complete = true;
                    }
                    else
                    {
                        temp= temp->right;
                    }
                }
                else
                    return -1;
                depth++;
            }
            while (!complete);
            n++;
            q++;
            return depth;
}
 
TreeNode* DataStructure::buildBalancedTree(TreeNode **tree,int i,int over){
    
    if(over==0){
        
        return NULL;
    }
    
    int midValue=over/2;
    
    tree[i+midValue]->left=buildBalancedTree(tree,i,midValue);
    if(tree[i+midValue]->left!=NULL){
        tree[i+midValue]->left->parent=tree[i+midValue];
    }
    tree[i+midValue]->right=buildBalancedTree(tree,i+midValue+1,over-midValue-1);
    if(tree[i+midValue]->right!=NULL){
        tree[i+midValue]->right->parent=tree[i+midValue];
    }
    return tree[i+midValue];
}

 
int
DataStructure  ::storeInArray(TreeNode  * node,TreeNode* datas[],int i){
    
    if(node==NULL){
        return i;
    }
    i=storeInArray(node->left,datas,i);
    datas[i++]=node;
    return storeInArray(node->right,datas,i);
}

 
void
DataStructure  ::rebuildTree(TreeNode* tree){
    
    int nodeSize=size1(tree);
    TreeNode   *p=tree->parent;
    TreeNode   **a=new TreeNode*[nodeSize];
    storeInArray(tree,a,0);
    if(p==NULL){
        root=buildBalancedTree(a,0,nodeSize);
        root->parent=NULL;
        
    }else if(p->right==tree){
        p->right=buildBalancedTree(a,0,nodeSize);
        p->right->parent=p;
        
    }else{
        p->left=buildBalancedTree(a,0,nodeSize);
        p->left->parent=p;
        
    }
}

bool
DataStructure  ::insertValue( int key,  double data){
    TreeNode  * node1=new TreeNode  (key,data);
    int depth=findDepthWhileAdding(node1);
    if(depth>log32(q)){
        //finding scapegoat if depth is exceeded
        
        TreeNode* temp=node1->parent;
        while(3*size1(temp)<=2*size1(temp->parent)){
            temp=temp->parent;
        }
        cout<<"ScapeGoat Found: "<<temp->parent->getValue()<<endl;;
        rebuildTree(temp->parent);
    }
    return depth>=0;
}
 
void
DataStructure  ::printGraphically(TreeNode  * tree,int space){
    if(tree==NULL){   //Base Case
            return;
        }
        space+=SPACE; //Increase distance between levels
        printGraphically(tree->right,space); //Process right child first
        cout<<endl;
        for(int i=SPACE; i<space; i++) //print current node after space count
        {
            cout<<" ";
        }
        cout<<tree->getValue()<<"\n";
        printGraphically(tree->left,space); //Process left child
}
TreeNode*
DataStructure::searchValue(double val){
    if(root==NULL)
        {
            return NULL;
        }
        else
        {
            TreeNode *temp=root;
            while(temp!=NULL)
            {
                if(val==temp->getValue())
                {
                    return temp;
                    break;
                }
                else if(val<temp->getValue())
                {
                    temp=temp->left;
                }
                else
                {
                    temp=temp->right;
                }
            }
            return NULL;
        }
}
void 
DataStructure::preOrderTraversal(TreeNode *tree)
    {
        if(tree==NULL)
        {
            return;
        }
        cout<<tree->getValue()<<" ";
        preOrderTraversal(tree->left);
        preOrderTraversal(tree->right);
    }
void
DataStructure::inOrderTraversal(TreeNode *tree)
    {
        if (tree==NULL)
        {
            return;
        }
        inOrderTraversal(tree->left);
        cout<<tree->getValue()<<" "; 
        inOrderTraversal(tree->right);
    }
void
DataStructure::postOrderTraversal(TreeNode *tree)
    {
        if(tree==NULL)
        {
            return;
        }
        postOrderTraversal(tree->left);
        postOrderTraversal(tree->right);
        cout<<tree->getValue()<<" ";
    }
int
DataStructure::heightOfScapeGoatTree(TreeNode * tree)
    {
        if(tree==NULL)
        {
            return -1;
        }
        else
        {
            int leftHeight=heightOfScapeGoatTree(tree->left);
            int rightHeight=heightOfScapeGoatTree(tree->right);
            if(leftHeight>rightHeight)
            {
                return(leftHeight+1);
            }
            else
            {
                return(rightHeight+1);
            }
        }
    }
void
DataStructure::breadthFirstTraversal(TreeNode *tree)
    {
        int height=heightOfScapeGoatTree(tree);
        for(int i=0; i<=height; i++)
        {
            printLevel(tree,i);
        }
    }
void
DataStructure::printLevel(TreeNode *tree,int level)
    {
        if(tree==NULL)
        {
            return;
        }
        else if(level==0)
        {
            cout<<tree->getValue()<<" ";
        }
        else
        {
            printLevel(tree->left,level-1);
            printLevel(tree->right,level-1);
        }
    }
