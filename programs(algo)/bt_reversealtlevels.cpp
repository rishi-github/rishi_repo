#include<iostream>
using namespace std;
#include<math.h>
#include<cmath>
#include<string.h>
#include<list>
#include<functional>

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

//use it only when individual lists contains duplicate elements
void bfs_utility(btnode* node)
{
int count=0;
list<btnode*> q;
if(node)
{q.push_back(node);
count++;
}
//btnode ptr;
while(!q.empty())
{
btnode *ptr=q.front();
q.pop_front();

if(ptr->left)
{
q.push_back(ptr->left);
count++;
}
if(ptr->right)
{
q.push_back(ptr->right);
count++;
}
//reverse the contents of the list
if(!(log(count+1)/log(2))%2)
{
list<btnode*>::iterator f;
list<btnode*>::iterator r;
//list<btnode*>::iterator e=q.en
//print starts
for(f=q.begin(),f=q.end(); it != q.end(); it++)
{
cout<<"  "<<(*f)->data;
f++;

}
f=q.begin();
while(f<e)
{
int temp=(*f)->data;
(*f)->data=temp;
(*e)->data;=(*f)->data;
f++;
e--;

}
f=q.begin();
e=q.end();
while(f<=e)
{
cout<<"  "<<(*f)->data;
f++;

}
//printing ends gere


}//ifclose


}
}


int main()
{
//btnode* n15=new btnode(15,NULL,NULL);
btnode* n14=new btnode(14,NULL,NULL);
btnode* n13=new btnode(13,NULL,NULL);
btnode* n12=new btnode(12,NULL,NULL);
btnode* n11=new btnode(11,NULL,NULL);
btnode* n10=new btnode(10,NULL,NULL);
btnode* n9=new btnode(9,NULL,NULL);
btnode* n8=new btnode(8,NULL,NULL);
btnode* n7=new btnode(7,NULL,NULL);
btnode* n6=new btnode(6,n13,n14);
btnode* n5=new btnode(5,n11,n12);
btnode* n4=new btnode(4,n9,n10);
btnode* n3=new btnode(3,n7,n8);
btnode* n2=new btnode(2,n5,n6);
btnode* n1=new btnode(1,n3,n4);
btnode* n0=new btnode(0,n1,n2);

}



