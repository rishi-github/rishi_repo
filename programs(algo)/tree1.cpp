#include<iostream>
using namespace std;
#include<math.h>
#include<cmath>
#include<string.h>
#include<list>
#include<functional>
#include<stack>
#include<vector>
#include<map>


class btnode
{
public:
int data;
btnode* left;
btnode* right;
btnode(int data,btnode* left,btnode* right)
{
this->data=data;
this->left=left;
this->right=right;


}
};
//llnode* start=NULL;

static int track=-1;
static int count1=0;
bool fail=false;
//use it only when individual lists contains duplicate elements
void is_leafatsamelevel(btnode* node)
{

if(!node || fail)
return;

count1++;
if(!node->left && !node->right)
{
cout<<endl<<node->data<<count1;
if(track==-1)
track=count1;
else if(track!=count1)
{fail=true;

}
else
return;

}


if(node->left)
{
is_leafatsamelevel(node->left);
count1--;
}
if(node->right)
{
is_leafatsamelevel(node->right);
count1--;
}


}

//--------------------------------------------------------
int max_dist=-1;
bool is_bt_a_subtree(btnode* node,btnode *subtree)
{

if(!subtree)
return true;
if(!node)
return false;

bool res=false;
if(node->data==subtree->data)
res=(is_bt_a_subtree(node->left,subtree->left) & is_bt_a_subtree(node->right,subtree->right));
res=res || is_bt_a_subtree(node->left,subtree) || is_bt_a_subtree(node->right,subtree);

return res;
}

//------------------------------------

//---------------------------------------------
int max1=-1;
int max_dist_leafs(btnode* node)
{
if(!node)
return 0;

int a=max_dist_leafs(node->left);
int b=max_dist_leafs(node->right);
max1=max(max1,a+b);
return 1+max(a,b);

}

//---------------------------

//************************************


int find_index(int * in,int val,int s,int e)
{
//int temp=s;
while(s<=e)
{
if(in[s]==val)
return s;
s++;
}
return -1;

}


int global=-1;
btnode* buildtree_from_pre_in(int *in,int * pre,int ins,int ine)
{
if(ins>ine)
return NULL;

global++;
btnode*temp=NULL;

if(ins==ine)
{
temp=new btnode(pre[global],NULL,NULL);
return temp;
}

else if(ine>ins)
{
temp=new btnode(pre[global],NULL,NULL);
int ind=find_index(in,pre[global],ins,ine);
temp->left=buildtree_from_pre_in(in,pre,ins,ind-1);
temp->right=buildtree_from_pre_in(in,pre,ind+1,ine);

}
return temp;
}


void inorder_traverse(btnode* ptr)
{
if(ptr)
{
inorder_traverse(ptr->left);
cout<<" "<<ptr->data;
inorder_traverse(ptr->right);

}
}

void preorder_traverse(btnode* ptr)
{
if(ptr)
{
cout<<" "<<ptr->data;
preorder_traverse(ptr->left);
preorder_traverse(ptr->right);

}
}
//********************************

btnode* lca_dfs(btnode* ptr,int a,int b)
{

if(!ptr)
return NULL;
if(a==b)
return ptr;

bool flaga=false,flagb=false;
stack<btnode*> s1;
s1.push(ptr);
btnode *val;
while(!s1.empty())
{
val=s1.top();
s1.pop();
//---------
if(val->data==a)
{
flaga=true;
btnode* marker=new btnode(-1,NULL,NULL);
s1.push(marker);
}
if(val->data==b)
{
flagb=true;
btnode* marker=new btnode(1,NULL,NULL);
s1.push(marker);
}
//--------
if(val->left)
s1.push(val->left);
if(val->right)
s1.push(val->right);


}



}

//+++++++++++++++++++++++++++++++++++++++++=
void bt_print_vertical(btnode* ptr,int val,map<int,vector<int> > &m)
{
//map<int,vector<int>> b;
if(!ptr)
return;
m[val].push_back(ptr->data);

bt_print_vertical(ptr->left,val-1,m);
bt_print_vertical(ptr->right,val+1,m);


}


//++++++++++++++++++++++++++++++++++++++++++
//&&&&&&&&&&&&&&&&&&&&
btnode* prev=NULL;
//btnode *start=0;
//bool flag=false;
btnode* leaf_dll(btnode* ptr)
{
if(!ptr)
return NULL;

if(!ptr->left && !ptr->right)
{
ptr->left=prev;
prev=ptr;

}
else
{
leaf_dll(ptr->left);
leaf_dll(ptr->right);
}
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


btnode* leaf_dll1(btnode* ptr,bool child,btnode** ret)
{
if(!ptr)
return NULL;

if(!ptr->left && !ptr->right)
{
*ret=ptr;
return ptr;
}

else
{
btnode *leftmax=NULL;
btnode *rightmax=NULL;
btnode* leftmin=leaf_dll1(ptr->left,0,&leftmax);
btnode* rightmin=leaf_dll1(ptr->right,1,&rightmax);
if(leftmax && rightmin)
{
leftmax->right=rightmin;
rightmin->left=leftmax;
*ret=rightmax;
return leftmin;
}

if(!rightmin)
{
*ret=leftmax;
return leftmin;
}
if(!leftmin)
{
*ret=rightmax;
return rightmin;

}
}
}
//&&&&&&&&&&&&&&&&&&&&
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int gcount=0;
void sum_root_to_leaf(btnode* node)
{
if(!node)
return;
gcount+=node->data;
if(!node->left && !node->right)
cout<<" "<<gcount;
else
{
sum_root_to_leaf(node->left);
sum_root_to_leaf(node->right);
}
gcount-=node->data;


}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//converts bst to sorted dll or any binary tree to dll
btnode* hoolala=NULL;
btnode* start=NULL;
bool flag=true;
void bst_dll(btnode* ptr)
{
if(!ptr)
return;

if(ptr->left)
bst_dll(ptr->left);


ptr->left=hoolala;
if(hoolala)
hoolala->right=ptr;
hoolala=ptr;

if(flag)
{
start=hoolala;
flag=false;
}
if(ptr->right)
bst_dll(ptr->right);

}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``

//((((((((((((((((((((((((((((((((((((((((((((((

int deletenode_min_sum_path(btnode * node,int k,int david)
{
if(!node)
return -1;

david+=node->data;
if(!node->left && !node->right)
{
if(david<k)
return -1;
return 0;
}
int a=deletenode_min_sum_path(node->left,k,david);
int b=deletenode_min_sum_path(node->right,k,david);

if(a==-1)//denotes kill me
{
delete(node->left);
node->left=NULL;
}
if(b==-1)
{
delete(node->right);
node->right=NULL;
}


if(a==b && b==-1)
return -1;

return 0;

}
//(((((((((((((((((((((((((((((((((((((((((((((((((

//###########################################
int apple=0;
btnode* buildtree_from_level_in(int *in,int *level,int val,int l,int r)
{
//apple++;
btnode* tmp=new btnode(val,NULL,NULL);
if(l==r)
return tmp;


int a=find_index(in,val,l,r);
int b=find_index(in,level[apple],l,r);
int c=find_index(in,level[apple+1],l,r);
int f=0;
cout<<endl;
cout<<apple<<" "<<a<<" "<<b<<" "<<c;




// b in left and cin right
if(b!=-1 && b>=l && b<a && c!=-1 && c>a && c<=r)
{
apple+=2;
tmp->left=buildtree_from_level_in(in,level,level[apple],l,a-1);
tmp->right=buildtree_from_level_in(in,level,level[apple+1],a+1,r);
}

//b in right
if(b!=-1 && b>a && b<=r)
{
apple++;
tmp->right=buildtree_from_level_in(in,level,level[apple],a+1,r);
f++;
}

if(c!=-1 && c>=l && c<a)
{
tmp->left=buildtree_from_level_in(in,level,level[apple+1],l,a-1);
f++;
}





//apple+=f;
return tmp;
}

//###########################################

int main()
{
//btnode* n15=new btnode(15,NULL,NULL);
/*btnode* n14=new btnode(14,NULL,NULL);
btnode* n13=new btnode(13,NULL,NULL);
btnode* n12=new btnode(12,NULL,NULL);
btnode* n11=new btnode(11,NULL,NULL);
btnode* n10=new btnode(10,NULL,NULL);
btnode* n9=new btnode(9,NULL,NULL);
btnode* n8=new btnode(8,NULL,NULL);
btnode* n7=new btnode(7,NULL,NULL);
btnode* n6=new btnode(6,n13,n14);
btnode* n5=new btnode(5,n11,NULL);
btnode* n4=new btnode(4,NULL,NULL);
btnode* n3=new btnode(3,n7,n8);
btnode* n2=new btnode(2,n5,n6);
btnode* n1=new btnode(1,n3,n4);
btnode* n0=new btnode(0,n1,n2);
*/
int visited[15];
for(int j=0;j<15;j++)
visited[j]=0;
//is_leafatsamelevel(n0);
//bool res=is_bt_a_subtree(n0,);
//int res=max_dist_leafs(n0);

//***************
//btnode * ptr=buildtree_from_pre_in(in,pre,0,6);
//inorder_traverse(ptr);
//preorder_traverse(ptr);

//****************

//++++++++++++++++++++++++++
/*map<int,vector<int> > m;
bt_print_vertical(n0,0,m);
map<int,vector<int> >::iterator it;
for(it=m.begin();it!=m.end();it++)
{
for(int i=0;i<it->second.size();i++)
cout<<" "<<it->second[i];
cout<<endl;
}
*/
//++++++++++++++++++++++++++++

//&&&&&&&&&&&
/*btnode* garb=NULL;
btnode* node=leaf_dll1(n0,1,&garb);
//node=start;
//cout<<node->data<<endl;
node=garb;
while(node!=NULL)
{cout<<" "<<node->data;

node=node->left;
}*/
//&&&&&&&&

//~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
btnode* n8=new btnode(8,NULL,NULL);
btnode* n4=new btnode(4,NULL,NULL);
btnode* n1=new btnode(1,NULL,NULL);

btnode* n7=new btnode(7,NULL,n8);
btnode* n5=new btnode(5,n4,NULL);
btnode* n2=new btnode(2,n1,NULL);
btnode* n3=new btnode(3,n2,n5);
btnode* n6=new btnode(6,n3,n7);
//btnode* n0=new btnode(0,n1,n2);


btnode* node=NULL;
bst_dll(n6);
node=hoolala;
while(node!=NULL)
{cout<<" "<<node->data;

node=node->left;
}
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~
btnode* n8=new btnode(8,NULL,NULL);
btnode* n4=new btnode(4,NULL,NULL);
btnode* n1=new btnode(1,NULL,NULL);

btnode* n7=new btnode(7,NULL,n8);
btnode* n5=new btnode(5,n4,NULL);
btnode* n2=new btnode(2,n1,NULL);
btnode* n3=new btnode(3,n2,n5);
btnode* n6=new btnode(6,n3,n7);

//deletenode_min_sum_path(n6,13,0);
//preorder_traverse(n6);
//##########################
int in[]={4,8,10,12,20,14,22};
int level[]={20,8,22,4,12,14,10};
btnode *res=buildtree_from_level_in(in,level,20,0,6);
//inorder_traverse(res);

//###############

}




