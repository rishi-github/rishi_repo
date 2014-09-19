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
llnode* start=NULL;

//use it only when individual lists contains duplicate elements
llnode* next_unique(llnode* ptr)
{
int hoo=ptr->data;
ptr=ptr->next;
while(ptr && ptr->data==hoo)
{
ptr=ptr->next;
}
return ptr;

}



void ll_intersect(llnode* a,llnode* b)
{
if(a && b)
{
    llnode* x=next_unique(a);
    llnode* y=next_unique(b);
    if(a->data==b->data)
    {
    ll_intersect(x,y);
    a->next=start;
    start=a;
    }
    if(a->data<b->data)
    {
    ll_intersect(x,b);
    }
    if(b->data<a->data)
    {
    ll_intersect(a,y);

    }
}



}

int main()
{
llnode* n1=new llnode(42,NULL);
llnode* n2=new llnode(24,n1);
llnode* n3=new llnode(18,n2);
llnode* n4=new llnode(16,n3);
llnode* n5=new llnode(1,n4);
llnode* n6=new llnode(24,NULL);
llnode* n7=new llnode(24,n6);
llnode* n8=new llnode(16,n7);
llnode* n9=new llnode(9,n8);
llnode* n10=new llnode(2,n9);
ll_intersect(n10,n5);
llnode* res=start;
while(res)
{
cout<<" "<<res->data;
res=res->next;

}
}

