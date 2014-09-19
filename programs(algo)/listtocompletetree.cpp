#include<malloc.h>
#include<iostream>
#include<string.h>
#include<list>
using namespace std;

//linked list node
struct Node
{
    char data;
    struct Node * next;
};
//tree node
struct Treenode
{
    char data;
    struct Treenode *left,*right;

};

void printtree(Treenode *ptr)
{
//Treenode *tmp=ptr;
static int count =0;
count++;
//if(count==5)
 //   exit;
if(ptr==NULL)
    return;

    cout<<endl<<ptr->data;
    printtree(ptr->left);
    printtree(ptr->right);

}

void printlist(Node *ptr)
{
//Treenode *tmp=ptr;
if(ptr)
{
    cout<<endl<<ptr->data;
    printlist(ptr->next);
    //printtree(ptr->right);
}
}

//for finding maximum in res
void createlist(Node *a)
{
    //Node * a=(Node*)malloc(sizeof(Node));
    Node * b=(Node*)malloc(sizeof(Node));
    Node * c=(Node*)malloc(sizeof(Node));
    Node * d=(Node*)malloc(sizeof(Node));
    Node * e=(Node*)malloc(sizeof(Node));
    Node * f=(Node*)malloc(sizeof(Node));
    Node * g=(Node*)malloc(sizeof(Node));
    Node * h=(Node*)malloc(sizeof(Node));
    Node * i=(Node*)malloc(sizeof(Node));
    a->data='a';a->next=b;
    b->data='b';b->next=c;
    c->data='c';c->next=d;
    d->data='d';d->next=e;
    e->data='e';e->next=f;
    f->data='f';f->next=g;
    g->data='g';g->next=h;
    h->data='h';h->next=i;
    i->data='i';i->next=NULL;




    //return a;
}

int main()
{
Node *start=(Node *)malloc(sizeof(Node));
createlist(start);
list<Treenode*> queue;
Treenode * n1=(Treenode *)malloc(sizeof(Treenode));
n1->data=start->data;
n1->left=NULL;
n1->right=NULL;
Node *track=start->next;
queue.push_back(n1);
Treenode *tmp,*n2,*n3;

while(!queue.empty() && track!=NULL)
{
    tmp=queue.front();
    queue.pop_front();
    if(track!=NULL)
    {
        n2=(Treenode *)malloc(sizeof(Treenode));
        n2->data=track->data;
        n2->left=NULL;
        n2->right=NULL;
        track=track->next;
        tmp->left=n2;
       // printtree(tmp);
        queue.push_back(n2);
    }
    if(track!=NULL)
    {
        n3=(Treenode *)malloc(sizeof(Treenode));
        n3->data=track->data;
        n3->left=NULL;
        n3->right=NULL;
        track=track->next;
        tmp->right=n3;
       // printtree(tmp);
        queue.push_back(n3);
    }



}
printtree(n1);
//cout<<endl<<n1->data;


}
