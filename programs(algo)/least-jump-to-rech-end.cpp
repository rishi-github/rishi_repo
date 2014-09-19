#include<iostream>


#include<string.h>
#include<math.h>
#define INFINITY INT_MAX
using namespace std;

int funrecur(int *arr,int size,int pos)
{
    //int table[size];
    if(size<=0) return INFINITY;
    if(size==1)return 0;
    if(arr[pos]>=size-1-pos)
        return 1;
    if(arr[pos]==0)
        return INFINITY;
        int res=INFINITY;
    for(int i=1;i<=arr[pos];i++)
    {
        res=min(res,funrecur(arr,size,pos+i));

    }
    if(res!=INFINITY)
        return res+1;
    return INFINITY;
}
int fun(int *arr,int size,int pos,int * table)
{
    if(size<=0) return INFINITY;
    if(size==1)return 0;
    if(table[pos]!=-1)
        return arr[pos];
    if(arr[pos]>=size-1-pos)
        {
            table[pos]=1;
            return 1;
        }
    if(arr[pos]==0)
    {
        table[pos]=INFINITY;
        return INFINITY;
    }

        int res=INFINITY;
    for(int i=1;i<=arr[pos];i++)
    {
        res=min(res,funrecur(arr,size,pos+i));

    }
    table[pos]=INFINITY;
    if(res!=INFINITY)
        {return res+1;table[pos]=res+1;}
    return INFINITY;
}



int main()
{
int arr[]={1,2,3,0,0,1,1,1,0};
int size=sizeof(arr)/sizeof(int);

int table[size];
for(int i=0;i<size;i++)
    {
        table[i]=-1;

    }
int res=fun(arr,size,0,table);
if(res!=INFINITY)
cout<<endl<<res;
else
cout<<endl<<"cannot reach to end from start";

}
