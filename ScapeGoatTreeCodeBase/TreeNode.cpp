#include "TreeNode.h"
#include<iostream>
using namespace std;

template<typename ItemType>
TreeNode<ItemType>::TreeNode(){
    key=NULL;
    left=NULL;
    right=NULL;
}
template<typename ItemType>
TreeNode<ItemType>::TreeNode(int k,int v){
    key=k;
    data=v;
}
template<typename ItemType>
ItemType TreeNode<ItemType>::getKey(){
    cout<<this->key;
}
template<typename ItemType>
ItemType TreeNode<ItemType>::getValue(){
    return this->data;
}
template<typename ItemType>
void TreeNode<ItemType>::setKey(int k){
    key=k;
}
template<typename ItemType>
void TreeNode<ItemType>::setValue(int v){
    data=v;
}
template<typename ItemType>
void TreeNode<ItemType>::printValue(TreeNode *r){
    //return 0;
}