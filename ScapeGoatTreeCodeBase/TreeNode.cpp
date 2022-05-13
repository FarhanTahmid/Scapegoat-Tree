#include "TreeNode.h"
#include<iostream>
using namespace std;

TreeNode::TreeNode(){
    setKey(0);
    setValue(0.0);
    left=NULL;
    right=NULL;
}

TreeNode::TreeNode(int k,double v){
    setKey(k);
    setValue(v);
    left=NULL;
    right=NULL;
}

int TreeNode::getKey(){
    return this->key;
}

double TreeNode::getValue(){
    return this->data;
}

void TreeNode::setKey(int k){
    this->key=k;
}

void TreeNode::setValue(double v){
    this->data=v;
}
