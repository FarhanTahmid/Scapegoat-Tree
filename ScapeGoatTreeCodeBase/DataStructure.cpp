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
    cout<<"log32 ans: "<<(int)ceil(log23*log(number))<<endl;
    cout<<"Q here : "<<number<<endl;
    return (int)floor(log23*log(number));
}
 
int DataStructure::findDepthWhileAdding(TreeNode  * u){
    TreeNode   *w = root;
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
    cout <<"INSIDE store in array"<<endl;
    if(node==NULL){
        return i;
    }
    i=storeInArray(node->left,datas,i);
    datas[i++]=node;
    return storeInArray(node->right,datas,i);
}

 
void
DataStructure  ::rebuildTree(TreeNode* tree){
    cout<<"inside rebuild tree"<<endl;
    int nodeSize=size1(tree);
    TreeNode   *p=tree->parent;
    TreeNode   **a=new TreeNode*[nodeSize];
    storeInArray(tree,a,0);
    if(p==NULL){
        root=buildBalancedTree(a,0,nodeSize);
        root->parent=NULL;
        cout<<"inside rebuild tree if"<<endl;
    }else if(p->right==tree){
        p->right=buildBalancedTree(a,0,nodeSize);
        p->right->parent=p;
        cout<<"inside rebuild tree else if"<<endl;
    }else{
        p->left=buildBalancedTree(a,0,nodeSize);
        p->left->parent=p;
        cout<<"inside rebuild tree else"<<endl;
    }
 }

bool
DataStructure  ::insertValue( int key,  double data){
    TreeNode  * node1=new TreeNode  (key,data);
    int depth=findDepthWhileAdding(node1);
    cout <<"depth outside the if condition "<<depth<<endl;
    cout<<"Q in insertvlaue"<<q<<endl;
    if(depth>log32(q)){
        cout<<"value of depth inside insertValue "<<depth<<endl;
        //finding scapegoat if depth is exceeded
        cout<<"Inside the if loop"<<endl;
        TreeNode* temp=node1->parent;
        while(3*size1(temp)<=2*size1(temp->parent)){
            temp=temp->parent;
        }
        cout<<"ScapeGoat"<<temp->getValue();
        rebuildTree(temp->parent);
    }
    return depth>=0;
}
 
void
DataStructure  ::printGraphically(TreeNode  * tree,int space){
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
