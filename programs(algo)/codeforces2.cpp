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
//#include "heap-operations.cpp"
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








int main()
{
ll a,b,c;
cin>>a;
cin>>b;
cin>>c;
ll arr[10002];
ll flag=0;
ll res=0;
ll grt=0;

//ll bitcount;
while(b--)
{
cin>>arr[flag];
flag++;
}
//cout<<flag;

cin>>grt;
//ll res=0;



for(ll i=0;i<flag;i++)
{

ll bitcount=0;
ll ret=grt^arr[i];
//ll d=count1(ret);
ll test=1;
while(test!=0)
{
bitcount+=(test&ret)?1:0;
test<<=1;//test<<1;
}



if(bitcount<=c)
res++;

}

cout<<res;

}
