#include<iostream>
using namespace std;
#include<math.h>
#include<string.h>
class llnode
{
public:
int data;
llnode* next;
llnode(int data,llnode* next)
{
this->data=data;
this->next=next;

}
};
class bstnode
{
public:
int data;
bstnode* left;
bstnode* right;
bstnode(int data)
{
this->data=data;
this->left=NULL;
this->right=NULL;

}
};
bstnode* sll_bst(llnode* ptr)
{
if(!ptr)
return NULL;
if(!ptr->next)
{
bstnode *tmp=new bstnode(ptr->data);
return tmp;
}
llnode *slow=ptr,*fast=ptr,*temp1=NULL,*temp2=NULL,*prev=NULL;
while(fast->next!=NULL && fast->next->next!=NULL)
{
prev=slow;
slow=slow->next;
fast=fast->next->next;

}
temp2=slow->next;
if(prev)
{
prev->next=NULL;
temp1=ptr;
}
bstnode *bst=new bstnode(slow->data);
slow->next=NULL;
delete(slow);
bst->left=sll_bst(temp1);
bst->right=sll_bst(temp2);
return bst;
}
static bool flag=true;
static bstnode*strt=NULL;
 bstnode * inorder_bst(bstnode* ptr,bstnode* t1,bstnode *t2)
{
if(!ptr)
return ptr;
llnode* left=NULL,*right=NULL;
if(ptr->left==NULL && ptr->right==NULL)
{
if(flag)
{strt=ptr;
flag=false;
}
ptr->left=t1;
ptr->right=t2;
*log=ptr;
return ptr;
}

else if(ptr->right==NULL)
{
ptr->right=t2;
}
else if(ptr->left==NULL)
{
ptr->left=t1;
}
else
{
bstnode *tmp2=NULL,*tmp3=NULL;
tmp2=inorder_bst(ptr->left,t1,ptr);
ptr->left=tmp2;
//cout<<" "<<ptr->data;
tmp3=inorder_bst(ptr->right,ptr,t2);
ptr->right=*log;
*log=tmp3;
return tmp2;

}

}
int main()
{
llnode* n1=new llnode(45,NULL);
llnode* n2=new llnode(23,n1);
llnode* n3=new llnode(8,n2);
llnode* n4=new llnode(7,n3);
llnode* n5=new llnode(6,n4);
llnode* n6=new llnode(4,n5);
llnode* n7=new llnode(2,n6);
//llnode *s=NULL;
bstnode *ptr=sll_bst(n7);
//s=mergesort_linkedlist(n7);
bstnode *res=inorder_bst(ptr,NULL,NULL);
bstnode *tmp1;
while(res)
{

cout<<endl<<res->right;
tmp1=res;
res=res->left;
}

}
