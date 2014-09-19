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
//rishi edits...........
#define priorityq priority_queue<listnode,vector<listnode>,listnodeCompare>
#define print_matrix loop(i,0,a){loop(j,0,b)cout<<" "<<mat[i][j];cout<<endl;}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void myswap(int &a,int &b)
{
a=a+b;
b=a-b;
a=a-b;

}
// reads the matrix from a file and flips it without using extra storage
void flip_matrix_by_90degree()
{
    ll a,b;
    cin>>a>>b;
    int mat[a][b];
    loop(i,0,a)
    loop(j,0,b)
    cin>>mat[i][j];

    cout<<"before calc......";
    print_matrix

    loop(i,0,(b+1)/2)
    {
    int knot=b-1-i;
    loop(j,i,b-i-1)
    {
    myswap(mat[i][j],mat[j][knot]);
    myswap(mat[i][j],mat[knot-(j-i)][i]);
    myswap(mat[knot-(j-i)][i],mat[knot][knot-(j-i)]);
    }
    }
    cout<<"after calc..........";
    print_matrix

}

int main()
{
flip_matrix_by_90degree();

return 0;
}
