// CONSTRCT A BINARY TREE IN C++
#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node *buildTree()
{  int  d;
   cin>>d;

    if(d==-1)
     return NULL;


   node* root=new node(d);
   root->left=buildTree();
   root->right=buildTree();

   return root;

}

void preOrderTraversal(node* root)
{
     if(root==NULL)
         return;
    cout<<root->data<<"  ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void InOrderTraversal(node* root)
{
     if(root==NULL)
         return;
   
    InOrderTraversal(root->left);
     cout<<root->data<<"  ";
    InOrderTraversal(root->right);
}

void PostOrderTraversal(node* root)
{
     if(root==NULL)
         return;
         PostOrderTraversal(root->left);
         PostOrderTraversal(root->right);
         cout<<root->data<<"  ";
}


int main() 
{
  node *root=buildTree(); 
 preOrderTraversal(root);
 cout<<endl;
InOrderTraversal(root);
cout<<endl;
 PostOrderTraversal(root);
return 0;
}