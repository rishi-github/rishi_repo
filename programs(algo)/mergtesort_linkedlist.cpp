#include<iostream>
using namespace std;
#include<math.h>
#include<string.h>
class node
{
public:
int data;
node* next;
node(int data,node* next)
{
this->data=data;
this->next=next;

}
};

void divide(node* start,node**a,node **b)
{
*a=start;
node* slow=start;
node* fast=start;

while(fast->next!=NULL && fast->next->next!=NULL)
{
slow=slow->next;
fast=fast->next->next;
}

*b=slow->next;
slow->next=NULL;


}

node * merge_list(node *a,node *b)
{
if(a==NULL && b==NULL)
{return a;
}
if(a==NULL)
return b;
if(b==NULL)
return a;


if(a->data<b->data)
{
a->next=merge_list(a->next,b);
return a;
}
else
{
b->next=merge_list(a,b->next);
return b;
}


}


node* mergesort_linkedlist(node *s)
{
if((s==NULL) || (s->next)==NULL)
return s;
node *a,*b,*c=NULL;
divide(s,&a,&b);
a=mergesort_linkedlist(a);
b=mergesort_linkedlist(b);
return merge_list(a,b);
/*node *temp=c;
while(temp)
{cout<<"  "<<temp->data;
temp=temp->next;
}cout<<endl;*/

//return c;
}


int main()
{
node* n1=new node(7,NULL);
node* n2=new node(6,n1);
node* n3=new node(5,n2);
node* n4=new node(4,n3);
node* n5=new node(3,n4);
node* n6=new node(2,n5);
node* n7=new node(2,n6);
node *s=NULL;
s=mergesort_linkedlist(n7);
while(s!=NULL)
{
cout<<" "<<s->data;
s=s->next;
}
}
