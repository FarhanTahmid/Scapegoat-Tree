#include "TreeNode.h"
#include<iostream>
using namespace std;

template<class ItemType>
TreeNode<ItemType>::TreeNode(){
    key=NULL;
    left=NULL;
    right=NULL;
}
template<class ItemType>
TreeNode<ItemType>::TreeNode(int k,int v){
    this->key=k;
    this->data=v;
}
template<class ItemType>
ItemType TreeNode<ItemType>::getKey(){
    return this->key;
}
template<class ItemType>
ItemType TreeNode<ItemType>::getValue(){
    return this->data;
}
template<class ItemType>
void TreeNode<ItemType>::setKey(ItemType k){
    this->key=k;
}
template<class ItemType>
void TreeNode<ItemType>::setValue(ItemType v){
    this->data=v;
}