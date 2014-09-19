#include<iostream>
using namespace std;
#include<math.h>
#include<string.h>

int carry=0;


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
llnode* global=NULL;
llnode* gonext(llnode* a,llnode* b,int diff);


llnode * ll_add(llnode *a,llnode *b)
{
int c1=0,c2=0;
llnode *tmp1,*tmp2;
tmp1=a;
while(tmp1)
{
c1++;tmp1=tmp1->next;
}
tmp1=b;
while(tmp1)
{
c2++;tmp1=tmp1->next;
}
if(c1>c2)
{
global=a;
tmp2=gonext(a,b,c1-c2);

}
else
{
global=b;
tmp2=gonext(b,a,c2-c1);
}
return tmp2;
}



llnode* gonext(llnode* a,llnode* b,int diff)
{

if(a==NULL && b==NULL)
return a;
else if(a==NULL)
return b;
else if(b==NULL)
return a;
llnode *garb=NULL;

if(diff)
garb=gonext(a->next,b,diff-1);
else{
garb=gonext(a->next,b->next,-1);
}

if(diff>0)
b->data=0;
int tmp=a->data+b->data+carry;
carry=0;
if(tmp/10)
carry=tmp/10;
a->data=tmp%10;

if(a==global && carry)
{
llnode *res=new llnode(carry,a);
return res;

}
return a;
}



int main()
{
llnode* n1=new llnode(9,NULL);
llnode* n2=new llnode(9,n1);
llnode* n3=new llnode(9,n2);
llnode* n4=new llnode(9,NULL);
llnode* n5=new llnode(9,NULL);
llnode* n6=new llnode(9,n5);
llnode* n7=new llnode(9,n6);
llnode *res=ll_add(n7,n3);
while(res)
{
cout<<" "<<res->data;

res=res->next;
}
//llnode *s=NULL;
}
