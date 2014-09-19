#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>

using namespace std;								/****JOYDEEP MONDAL****/
										/****IIT - R ****/

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
ld power(ld m,int n)
{
	ld result = 1;
	if(!n)
	return 1;
	ld temp=power(m,n/2);
	result=temp*temp;
	if(n&1)
	result*=m;
	return result;
}

ll gcd(ll a,ll b)
{
	if(!b)
	return a;
	if(!a)
	return b;
	if(a>b)
	return (gcd(b,a%b));
	return (gcd(a,b%a));
}

ll power_mod(ll m,ll n,ll mod)
{
	m%=mod;
	ll result =1;
	if(!n)
	return 1;
	ll temp;
	temp = power_mod(m,n/2,mod);
	temp%=mod;
	result = temp*temp;
	result %= mod;
	if(n&1)
	result*=m;
	result%=mod;
	return result;
}

ll lcm(ll a,ll b)
{
	ll result;
	result = (a*b)/gcd(a,b);
	return result;
}

class stair
{
	public:
	int d,p;
	bool operator<(const stair&) const;

};

bool stair :: operator<(const stair& m) const
{
	return ( d < m.d) ;
}

void floyd(ll )
{


}

/***************relevant code starts here******************/

dijkstra()



int main()
{


return 0;

}

