#include<iostream>
#include "TreeNode.cpp"
#include "DataStructure.h"
#include<list>
#include<math.h>
#define SPACE 10
using namespace std;

template<typename ItemType>
DataStructure<ItemType>::DataStructure(){
    root=NULL;
    n=0;
}

template<typename ItemType>
bool
DataStructure<ItemType>::isEmpty(){
    return root==NULL;
}
template<typename ItemType>
int //count number of nodes of a parent
DataStructure<ItemType>::size(TreeNode<ItemType>& tree){
    if(tree==NULL){
        return 0;
    }else{
        int size;
        size+=size(tree->left);
        size+=size(tree.right);
        return size;
    }
}

template<typename ItemType>
int
DataStructure<ItemType>::sizeofTree(){
    return n;
}

template<typename ItemType>
const int
DataStructure<ItemType>::log32(int number){
    double const log23=2.4663034623764317;
    return (int)ceil(log23*log(q));
}
template<typename ItemType>
int
DataStructure<ItemType>::findDepthWhileAdding(TreeNode<ItemType>& node){
    TreeNode<ItemType>*temp=root;
    if(temp==NULL){
        root=temp;
        n++;
        q++;
        return 0;
    }
    bool complete=false;
    int depth=0;
    do{
        if(node->getValue()<temp->getValue()){
            if(temp->left==NULL){
                temp->left==node;
                node->parent=temp;
                complete=true;
            }else{
                temp=temp->left;
            }
        }else if(node->getValue()>temp->getValue()){
            if(temp->right==NULL){
                temp->right=node;
                node->parent=temp;
                complete=true;
            }else{
                temp=temp->right;
                }
            }else{
                return -1;
            }
            depth++;                     
        
    }while(!complete);
    n++;
    q++;
    return depth;        
            
}
template<typename ItemType>
TreeNode<ItemType>* 
DataStructure<ItemType>::buildBalancedTree(TreeNode<ItemType> &&tree,int i,int over){
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

template<typename ItemType>
int
DataStructure<ItemType>::storeInArray(TreeNode<ItemType>& node,TreeNode<ItemType[]>& datas,int i){
    if(node==NULL){
        return i;
    }
    i=storeInArray(node->left,datas,i);
    datas[i++]=node;
    return storeInArray(node->right,datas,i);
}
template<typename ItemType>
void
DataStructure<ItemType>::rebuildTree(TreeNode<ItemType>& tree){
    int nodeSize=size(tree);
    TreeNode<ItemType> *p=tree->parent;
    TreeNode<ItemType> **a=new TreeNode<ItemType>* [nodeSize];
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
template<typename ItemType>
bool 
DataStructure<ItemType>::insertValue(ItemType key,ItemType data){
    TreeNode<ItemType>* node=new TreeNode(key,data);
    int depth=findDepthWhileAdding(node);
    if(depth>log32(q)){
        //finding scapegoat if depth is exceeded
        TreeNode<ItemType> *temp=node->parent;\
        while(3*size(temp)<=2*size(temp->parent)){
            temp=temp->parent;
        }
        return d>=0;
    }
}
template<typename ItemType>
void
DataStructure<ItemType>::printGraphically(TreeNode<ItemType>& tree,int space){
    if(tree==NULL)   //Base Case
        {
            return;
        }
        space+=SPACE; //Increase distance between levels
        print2D(tree->right,space); //Process right child first
        cout<<endl;
        for(int i=SPACE; i<space; i++) //print current node after space count
        {
            cout<<" ";
        }
        cout<<tree->value<<"\n";
        print2D(tree->left,space); //Process left child
}