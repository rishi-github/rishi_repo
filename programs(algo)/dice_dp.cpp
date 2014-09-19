#include<iostream>
#include<malloc.h>
using namespace std;
//bool var=false;

int allocate(int n,int m,int x,int ** store)
{

if(n==0 && x==0)
return 1;

else if((n==0) ||(x<=0))// remember this condition is very important for extreme ones.
return 0;

//check in table

if(store[n][x]!=-1)
    return store[n][x];

int var=0;
for(int i=1;i<=m;i++)
    {
        var=var+allocate(n-1,m,x-i,store);
    }
    store[n][x]=var;

return store[n][x];
}

//int store[5][2];

int main()
{

int n=1000000;
int m=10000;
int x=100000000;
//

//int store[n+1][x+1];
int ** store=(int **)malloc((n+1)*sizeof(int*));
for(int i=0;i<(n+1);i++)
store[i]=(int *)malloc((x+1)*sizeof(int));
for(int i=0;i<=n;i++)
for(int j=0;j<=x;j++)
store[i][j]=-1;



int  res=allocate(n,m,x,(int **)store);
cout<<endl<<res<<endl;

for(int i=0;i<=n;i++)
{for(int j=0;j<=x;j++)
//cout<<"   "<<store[i][j];
cout<<endl;

}
cout<<endl<<store[100][100];
}

