#include<iostream.h>
using namespace std;
#define v 4
int recur(int arr[][],int s,int d,int x)
{
    if(s==d && x=0)
        return 1;
    if(arr[s][d] && x==1)
        return 1;
    if(x<=0)
        return 0;
    int count=0;
    for(int i=0;i<v;i++)
    {
        if(arr[s][i])
            count=count+recur(arr,i,d,x-1);

    }
    return count;
}
int main()
{
    int mat[][v]={{0,0,0,1},{0,0,1,0},{1,0,0,0},{0,1,1,0}};
    cout<<endl<<recur(mat,0,0,4);


}
