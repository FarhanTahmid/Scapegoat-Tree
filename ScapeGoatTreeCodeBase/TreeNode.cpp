#include "TreeNode.h"
#include<iostream>
using namespace std;

template<typename ItemType>
TreeNode<ItemType>::TreeNode(){
    setKey(NULL);
    setValue(NULL);
    left=NULL;
    right=NULL;
}
template<typename ItemType>
TreeNode<ItemType>::TreeNode(ItemType& k,ItemType& v){
    setKey(k);
    setValue(v);
    left=NULL;
    right=NULL;
}
template<typename ItemType>
ItemType TreeNode<ItemType>::getKey(){
    return this->key;
}
template<typename ItemType>
ItemType TreeNode<ItemType>::getValue(){
    return this->data;
}
template<typename ItemType>
void TreeNode<ItemType>::setKey(ItemType& k){
    this->key=k;
}
template<typename ItemType>
void TreeNode<ItemType>::setValue(ItemType& v){
    this->data=v;
}
template<typename ItemType>
void TreeNode<ItemType>::printValue(TreeNode *r){
    //return 0;
}