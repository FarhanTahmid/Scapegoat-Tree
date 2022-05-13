#include<iostream>
#include "TreeNode.cpp"
#include "DataStructure.h"
#include<list>
#include<math.h>
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
template<typename ItemType>
template<typename ItemType>
template<typename ItemType>
template<typename ItemType>




template<typename ItemType>
void 
DataStructure<ItemType>::insertValue(ItemType,ItemType){
    
}

