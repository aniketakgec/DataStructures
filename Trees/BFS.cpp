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

void BFS(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node *f=q.front();
        cout<<f->data<<" ";
        q.pop();
        if(f->left!=NULL)
         q.push(f->left);
           if(f->right!=NULL)
         q.push(f->right);

    }
}

 
int main() 
{
  node *root=buildTree(); 
  BFS(root);
return 0;
}