#include<iostream>
using namespace std;
#include<malloc.h>

struct minheapnode
{
int v;
int dist;

};
struct minheap
{
int size;
int capacity;
minheapnode ** arr;
int * pos;

};

void insertheap(minheap *heap,int v,int dist);
bool isempty(minheap *heap);
void display_heap(minheap* heap);
void shiftdown(minheap* heap,int ind);
minheapnode* extractminimum(minheap * heap);
void swap_minheapnode(minheap* heap,int p1,int p2);
void decrease_key(struct minheap* heap,int p,int newdist);
void shiftup(struct minheap * heap,int p1);
minheapnode* create_minheapnode(int v,int dist);
minheap* create_minheap(int cap);
minheap* create_heap(int vsize,int source);




minheapnode* create_minheapnode(int v,int dist)
{
    minheapnode* ptr=(minheapnode*)malloc(sizeof(minheapnode));
    ptr->v=v;
    ptr->dist=dist;
    return ptr;

}

minheap* create_minheap(int cap)
{
    minheap* ptr=(minheap*)malloc(sizeof(minheap));
    ptr->size=0;
    ptr->capacity=cap;
    ptr->pos=(int *)malloc(ptr->capacity*sizeof(int));
    ptr->arr=(minheapnode**)malloc(ptr->capacity*sizeof(minheapnode*));
    for(int i=0;i<ptr->capacity;i++)
        ptr->pos[i]=-1;
    return ptr;

}
void insert_minheapnode()
{




}
void minheapify(minheap* heap,int ind)
{
int store=ind;
int left,right;
left=2*ind+1;
right=2*ind+2;
if(left < heap->size && heap->arr[heap->pos[left]]->dist < heap->arr[heap->pos[ind]]->dist);
ind=left;
if(right < heap->size && heap->arr[heap->pos[right]]->dist < heap->arr[heap->pos[ind]]->dist);
ind=right;

if(ind!=store)
{
    minheapnode* temp=heap->arr[heap->pos[ind]];
heap->arr[heap->pos[ind]]=heap->arr[heap->pos[store]];
heap->arr[heap->pos[store]]=temp;
int temp1=heap->pos[store];
heap->pos[store]=heap->pos[ind];
heap->pos[ind]=temp1;


minheapify(heap,ind);

}



}


// ccreate graph
minheap* create_heap(int vsize,int source)
{
    //int v=graph->v;
    int capacity=vsize;

    minheap * heap=create_minheap(capacity);
    heap->size=capacity;
    heap->pos[source]=0;
    //heap->size++;
    heap->arr[0]=(minheapnode*)malloc(sizeof(minheapnode));
    heap->arr[0]->v=source;
    heap->arr[0]->dist=0;


    int start=0;
    for(int i=1;i<capacity;i++)
    {

        heap->arr[i]=(minheapnode*)malloc(sizeof(minheapnode));
        if(start==source)
        {
            start++;
        }
        heap->arr[i]->v=start;
        heap->pos[start]=i;
        heap->arr[i]->dist=INT_MAX;

        //heap->size++;
        start++;
    }
return heap;
}


void shiftup(struct minheap * heap,int p)
{
    //int p=heap->pos[p1];
if(p && heap->arr[(p-1)/2]->dist > heap->arr[p]->dist)
{
minheapnode* temp=heap->arr[p];
heap->arr[p]=heap->arr[(p-1)/2];
heap->arr[(p-1)/2]=temp;
//int temp1=heap->arr[p]->v;
heap->pos[heap->arr[p]->v]=p;
heap->pos[heap->arr[(p-1)/2]->v]=(p-1)/2;

shiftup(heap,(p-1)/2);

}

}
void decrease_key(struct minheap* heap,int p,int newdist)
{
    int position=heap->pos[p];
    heap->arr[position]->dist=newdist;
    shiftup(heap,position);

    //if(p && heap->arr[pos/2]->dist>heap->arr[pos]->dist)
      //  shiftup(heap,)
}

void swap_minheapnode(minheap* heap,int p1,int p2)
{

    int x=heap->arr[p1]->v;
    int y=heap->arr[p2]->v;
    heap->pos[x]=p2;
    heap->pos[y]=p1;
    minheapnode *tmp=heap->arr[p1];
    heap->arr[p2]=heap->arr[p1];
    heap->arr[p1]=tmp;

}

minheapnode* extractminimum(minheap * heap)
{
    heap->size=heap->size-1;
    minheapnode* ptr=heap->arr[0];
    int v=ptr->v;
    heap->pos[v]=-1;
    if((heap->size)>0)
    {
        heap->arr[0]=heap->arr[heap->size];
        heap->arr[heap->size]=NULL;
        int v=heap->arr[0]->v;
        heap->pos[v]=0;
        // shift down to maintain heap property
        shiftdown(heap,0);

    }
    return ptr;
}
void shiftdown(minheap* heap,int ind)
{
int store=ind;
int left,right;
left=2*ind+1;
right=2*ind+2;
if((left < heap->size) && (heap->arr[left]->dist < heap->arr[ind]->dist))
ind=left;
if(right < heap->size && heap->arr[right]->dist < heap->arr[ind]->dist)
ind=right;

if(ind!=store)
{
    minheapnode* temp=heap->arr[ind];
heap->arr[ind]=heap->arr[store];
heap->arr[store]=temp;
heap->pos[heap->arr[store]->v]=store;
heap->pos[heap->arr[ind]->v]=ind;


shiftdown(heap,ind);

}
}





void display_heap(minheap* heap)
{


    cout<<endl<<"contents of pos are:";
    cout<<endl;
    for(int i=0;i<heap->capacity;i++)
    cout<<heap->pos[i];
    cout<<endl<<"size is "<<heap->size<<endl;
    cout<<endl<<"capacity is "<<heap->capacity<<endl;

}

bool isempty(minheap *heap)
{
    return !(heap->size);

}
void insertheap(minheap *heap,int v,int dist)
{
    if(heap->size < heap->capacity)
    {
    minheapnode * temp=(minheapnode*)malloc(sizeof(minheapnode));
    temp->v=v;
    temp->dist=dist;
    heap->size++;
    heap->arr[heap->size-1]=temp;
    heap->pos[v]=heap->size-1;
    shiftup(heap,heap->size-1);

    }
    //return heap;

}



int main()
{
minheap* heap=create_heap(5,3);
display_heap(heap);
extractminimum(heap);
extractminimum(heap);
extractminimum(heap);
extractminimum(heap);
extractminimum(heap);
display_heap(heap);
insertheap(heap,0,4);
insertheap(heap,1,2);
insertheap(heap,2,3);
insertheap(heap,3,0);
insertheap(heap,4,18);
insertheap(heap,5,0);
display_heap(heap);
minheapnode* temp=extractminimum(heap);
cout<<endl<<temp->v;
temp=extractminimum(heap);
cout<<endl<<temp->v;


temp=extractminimum(heap);
cout<<endl<<temp->v;
decrease_key(heap,4,1);
temp=extractminimum(heap);
cout<<endl<<temp->v;

temp=extractminimum(heap);
cout<<endl<<temp->v;


}

