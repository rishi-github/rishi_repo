#include<iostream>
using namespace std;



struct node
{
public:
int data;
int val;
node* left;
node* right;
node(int data);

};

node::node(int data)
{
data=data;
val=-1;
left=NULL;
right=NULL;
}

node* createtree()
{
node* a1=new node(1);
node* a2=new node(1);
node* a3=new node(1);
node* a4=new node(1);
node* a5=new node(1);
node* a6=new node(1);
node* a7=new node(1);
node* a8=new node(1);


a1->left=a2;
a1->right=a3;
a2->left=a4;
a2->right=a5;
a3->right=a6;
a5->left=a7;
a5->right=a8;
return a1;

}
int lis(node* root)
{
if(!root)
return 0;
if(root->val!=-1)
return root->val;
if(root->left==NULL && root->right==NULL)
return 1;
int a,b;
int child=lis(root->left)+lis(root->right);

if(root->left)
a=lis(root->left->left)+lis(root->left->right);

if(root->right)
b=lis(root->right->left)+lis(root->right->right);

int res=max(child,1+a+b);
root->val=res;
return res;

}


int main()
{
node * root=createtree();
lis(root);
cout<<endl<<root->val;

}

void showtree()
{

}
