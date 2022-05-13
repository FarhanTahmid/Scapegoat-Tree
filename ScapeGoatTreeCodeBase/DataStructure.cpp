#include<iostream>
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
DataStructure<ItemType>::size1(TreeNode<ItemType>* tree){
    if(tree==NULL){
        return 0;
    }else{
        int size=1;
        size+=size1(tree->left);
        size+=size1(tree->right);
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
    return (int)ceil(log23*log(number));
}
template<typename ItemType>
int
DataStructure<ItemType>::findDepthWhileAdding(TreeNode<ItemType>* u){
    TreeNode<ItemType> *w = root;
            if (w == NULL)
            {
                root = u;
                n++;
                q++;
                return 0;
            }
            bool done = false;
            int d = 0;
            do
            {
                if (u->getValue() < w->getValue())
                {
                    if (w->left == NULL)
                    {
                        w->left = u;
                        u->parent = w;
                        done = true;
                    }
                    else
                    {
                        w = w->left;
                    }
                }
                else if (u->getValue() > w->getValue())
                {
                    if (w->right == NULL)
                    {
                        w->right = u;
                        u->parent = w;
                        done = true;
                    }
                    else
                    {
                        w = w->right;
                    }
                }
                else
                    return -1;
                d++;
            }
            while (!done);
            n++;
            q++;
            return d;
}
template<typename ItemType>
TreeNode<ItemType>
DataStructure<ItemType>::buildBalancedTree(TreeNode<ItemType> **tree,int i,int over){
    cout<<"inside buildBalanced";
    if(over==0){
        cout<<"Inside first if"<<endl;
        return NULL;
    }
    cout<<"outside first if build balanced"<<endl;
    int midValue=over/2;
    cout<<"Mid Value"<<midValue;
    tree[i+midValue]->left=buildBalancedTree(tree,i,midValue);
    if(tree[i+midValue]->left!=NULL){
        tree[i+midValue]->left->parent=tree[i+midValue];
    }
    tree[i+midValue]->right=buildBalancedTree(tree,i+midValue+1,over-midValue-1);
    if(tree[i+midValue]->right!=NULL){
        tree[i+midValue]->right->parent=tree[i+midValue];
    }
    cout<<"tree[i+midvalue]"<<tree[i+midValue]<<endl;
    return tree[i+midValue];
}

template<typename ItemType>
int
DataStructure<ItemType>::storeInArray(TreeNode<ItemType>* node,TreeNode<ItemType[]>* datas,int i){
    cout <<"INSIDE store in array"<<endl;
    if(node==NULL){
        return i;
    }
    i=storeInArray(node->left,datas,i);
    datas[i++]=node;
    return storeInArray(node->right,datas,i);
}
template<typename ItemType>
void
DataStructure<ItemType>::rebuildTree(TreeNode<ItemType>* u){
    int ns = size1(u);
            TreeNode<ItemType> *p = u->parent;
            TreeNode<ItemType[]> **a = new TreeNode<ItemType[]> [ns];
            storeInArray(u, a, 0);
            if (p == NULL)
            {
                root = buildBalancedTree(a, 0, ns);
                root->parent = NULL;
            }
            else if (p->right == u)
            {
                p->right = buildBalancedTree(a, 0, ns);
                p->right->parent = p;
            }
            else
            {
                p->left = buildBalancedTree(a, 0, ns);
                p->left->parent = p;
            }
 }
template<typename ItemType>
bool
DataStructure<ItemType>::insertValue(ItemType key,ItemType data){
    TreeNode<ItemType>* node1=new TreeNode<ItemType>(key,data);
    int depth=findDepthWhileAdding(node1);
    if(depth>log32(q)){
        //finding scapegoat if depth is exceeded
        TreeNode<ItemType>* temp=node1->parent;\
        while(3*size1(temp)<=2*size1(temp->parent)){
            temp=temp->parent;
        }
        rebuildTree(temp->parent);
    }
    return depth>=0;
}
template<typename ItemType>
void
DataStructure<ItemType>::printGraphically(TreeNode<ItemType>* tree,int space){
    if(tree==NULL)   //Base Case
        {

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
