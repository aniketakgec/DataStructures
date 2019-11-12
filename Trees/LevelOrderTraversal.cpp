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

node* buildTree()
{  int  d;
   cin>>d;

    if(d==-1)
     return NULL;


   node* root=new node(d);
   root->left=buildTree();
   root->right=buildTree();

   return root;

}

int heightOfTree(node* root)
{
    if(root==NULL)
      return 0;
    int ldepth=heightOfTree(root->left);
    int rdepth=heightOfTree(root->right);
    return max(ldepth,rdepth)+1;
}
void printKthLevel(node *root,int k)
{
    if(root==NULL)
       return;

     if(k==1)
    { 
       cout<<root->data<<" ";
      return;
    }
     printKthLevel(root->left,k-1);
     printKthLevel(root->right,k-1);
     return;
}

void printLevelOrder(node* root)
{
    int h=heightOfTree(root);
    for(int i=1;i<=h;i++)
   { printKthLevel(root,i);
     cout<<endl;
   }
    
}
 
int main() 
{
  node *root=buildTree(); 
  printLevelOrder(root);
return 0;
}