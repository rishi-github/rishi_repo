#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<list>
//#include<priority_queue>
#include<stack>
#include<map>
//#include<unordered_map>
#include "heap-operations.cpp"
using namespace std;

#define ll long long int
#define ld double
#define pb push_back
#define bigger(a,b) (a>b?a:b)
#define smaller(a,b) (a<b?a:b)
#define o_di vector<int>
#define o_dl vector<ll>
#define o_dd vector<ld>
#define o_dc vector<stair>
#define loop(i,s,n) for(ll i=s;i<n;i++)
#define loope(i,s,n) for(ll i=s;i<=n;i++)
#define loopd(i,n,s) for(ll i=n-1;i>=s;i--)
#define loopde(i,n,s) for(ll i=n;i>=s;i--)
#define infinity 9999999
#define my_max 34
#define my_limit 1000000000
#define priorityq priority_queue<listnode,vector<listnode>,listnodeCompare>

class listnode
{
    public:
    int v;
    float w;
};
struct listnodeCompare
{
	bool operator()(const listnode &t1, const listnode &t2) const
	{
		int t1value = t1.w;
		int t2value = t2.w;
		return t1value < t2value;
	}
};
class create_graph
{
    public:
    int v;
    bool directed;
    list<listnode>* arr;

//    int get_v();
 //   void set_v(int v);
    create_graph(int v,bool directed);
    void addEdge(int u,int v,float w);
    void dijkstra(int source);
    void dijkstra_minheap(int source);
    void build_priority_queue(priority_queue<listnode,vector<listnode>,listnodeCompare> &refr);
    void display_adjlist();
    int dijkstra_minheap_pair(int,int);
    ll bellman_ford(ll src,ll dest);
};

// returns -1 upon presence of negative cycles
ll create_graph::bellman_ford(ll src,ll dest)
{
list<listnode>::iterator it;
ll spath[v];
loop(l,0,v)
spath[l]=infinity;
spath[src]=0;

loop(k,0,v-1)
loop(i,0,v)
for(it=arr[i].begin();it!=arr[i].end();it++)
{
if(spath[(*it).v]>spath[i]+(*it).w)
spath[(*it).v]=spath[i]+(*it).w;
}

//check for negative loops
loop(i,0,v)
for(it=arr[i].begin();it!=arr[i].end();it++)
{
if(spath[(*it).v]>spath[i]+(*it).w)
{
//spath[(*it).v]=spath[i]+(*it).w;
return -1;
}
return spath[dest];
}



}



void create_graph::build_priority_queue(priority_queue<listnode,vector<listnode>,listnodeCompare>& pq)//1-directed 0-undirected
{
    list<listnode>::iterator it;
    for(int i=0;i<v;i++)
    for(it=arr[i].begin();it!=arr[i].end();it++)
    {
        pq.push(*it);
    }

}

void create_graph::display_adjlist()
{
    list<listnode>::iterator it;
    for(int i=0;i<v;i++)
    {
        for(it=arr[i].begin();it!=arr[i].end();it++)
        {
            cout<<"  "<<(*it).v;
            //pq.push(*it);
        }
        cout<<endl;
    }
}


create_graph::create_graph(int v,bool directed)//1-directed 0-undirected
{
    this->v=v;
    this->arr= new list<listnode>[v];//(list<listnode>*)malloc(v*sizeof(list<listnode>));
    this->directed=directed;
    //for(int i=0;i<v;i++)
}
void create_graph::addEdge(int x,int y,float w)
{
    listnode *temp=new listnode;
    temp->v=y;
    temp->w=w;
    arr[x].push_back(*temp);

}


//using min heap

void create_graph::dijkstra_minheap(int source)
{
list<listnode>::iterator it;
minheap* heap=use_heap_dijkstra(v,source);

int spath[v];
for(int i=0;i<v;i++)
    spath[i]=infinity;

spath[source]=0;
while(heap->size)
{
minheapnode *ele=extractminimum(heap);
int minele=ele->v;
cout<<"  "<<minele;
for (it =arr[minele].begin(); it !=arr[minele].end(); it++)
    {
        if(spath[(*it).v]>spath[minele]+((*it).w))
        {
        spath[(*it).v]=spath[minele]+(*it).w;
        decrease_key(heap,(*it).v,spath[(*it).v]);

        }
    }
}
cout<<endl;
for(int i=0;i<v;i++)
    cout<<" "<<spath[i];
}
//using min heap

//______________________________________________________
//will return the shortest path betwen any two nodes
int create_graph::dijkstra_minheap_pair(int source,int dest)
{
list<listnode>::iterator it;
minheap* heap=use_heap_dijkstra(v,source);

int spath[v];
for(int i=0;i<v;i++)
    spath[i]=infinity;

spath[source]=0;
while(heap->size)
{
minheapnode *ele=extractminimum(heap);
int minele=ele->v;
//cout<<"  "<<minele;
for (it =arr[minele].begin(); it !=arr[minele].end(); it++)
    {
        if(spath[(*it).v]>spath[minele]+((*it).w))
        {
        spath[(*it).v]=spath[minele]+(*it).w;
        decrease_key(heap,(*it).v,spath[(*it).v]);

        }
    }
}
//cout<<endl;
//for(int i=0;i<v;i++)
  //  cout<<" "<<spath[i];
return spath[dest];
}


//________________________________________________________


//......................................................using priority queue
/*
void create_graph::dijkstra_priorityqueue(int source)
{
    priorityq pq;
    build_priority_queue(pq);
    list<listnode>::iterator it;
    //minheap* heap=create_heap(v,source);
    ld spath[v];

    for(int i=0;i<v;i++)
        spath[i]=infinity;
    spath[source]=0;
    while(!pq.empty())
    {
        listnode node=pq.top();
        pq.pop();
        int nodenum=node.v;
        for(it=arr[v].begin();it!=arr[v].end();it++)
        {
            if(spath[(*it).v]>spath[nodenum]+(*it).w)
            {
                spath[(*it).v]=spath[node.v]+(*it).w;
                listnode tmp=*it;

                //tmp.w=spath[tmp.v];
                //pq.push(tmp);
            }
        }
    }
    cout<<endl;
    for(int i=0;i<v;i++)
    cout<<" "<<spath[i];
}
*/





int test_dijkstra()
{


    //graph.dijkstra(0);
    int V = 9;
    create_graph graph(V,1);
    //graph.addEdge(0, 1, 4);
    /*
    graph.addEdge(0,1,5);
    graph.addEdge(0,3,8);
    graph.addEdge(0,2,2);
    graph.addEdge(2,3,1);
    graph.addEdge(3,1,1);
    graph.addEdge(3,4,4);
    graph.addEdge(1,4,3);
    */
    graph.addEdge(0,1,4);
    graph.addEdge(0,7,8);
    graph.addEdge(1,2,-3);
    graph.addEdge(2,0,1);
    graph.addEdge(1,7,11);
    graph.addEdge(2,3,7);
    graph.addEdge(2,8,2);
    graph.addEdge(2,5,4);
    graph.addEdge(3,4,9);
    graph.addEdge(3,5,14);
    graph.addEdge(4,5,10);
    graph.addEdge(5,6,2);
    graph.addEdge(6,7,1);
    graph.addEdge(6,8,6);
    graph.addEdge(7,8,7);

    ll res=graph.bellman_ford(0,2);

    cout<<res;//graph.display_adjlist();
    //graph.dijkstra(0);
    //priorityq pq;
    //graph.build_priority_queue(pq);




}
