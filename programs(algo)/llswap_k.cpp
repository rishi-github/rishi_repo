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
int k=3;
llnode* rem=NULL;


//utility functio for reversing the linked list for k elements.
llnode* reverse_k(llnode* node)
{
if(!node || !node->next)
return node;

llnode* tmp=NULL;
llnode* rem=NULL;
llnode* now=node;
int l=k;

while(l && now)
{

rem=now->next;
now->next=tmp;
tmp=now;
now=rem;
l--;
}
if(!l && now)
node->next=now;

return tmp;
}

llnode * llswap_k(llnode * start)
{
if(k==0 || k==1)
return start;
llnode* newstart=reverse_k(start);
if(start->next)
start->next=llswap_k(start->next);

return newstart;

}



int main()
{
llnode* n1=new llnode(45,NULL);
llnode* n2=new llnode(23,NULL);
llnode* n3=new llnode(8,n2);
llnode* n4=new llnode(7,n3);
llnode* n5=new llnode(6,n4);
llnode* n6=new llnode(4,n5);
llnode* n7=new llnode(2,n6);
llnode *res = llswap_k(n7);

while(res)
{
cout<<" "<<res->data;
res=res->next;

}
}
