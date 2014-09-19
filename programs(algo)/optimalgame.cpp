
#include<iostream>
#include<string.h>
using namespace std;


int fun(int *A,int lenA)
{

    int tmat[lenA][lenA];
    memset(tmat,0,sizeof(tmat));
    for(int i=0;i<lenA;i++)
    for(int j=0;j+i<lenA;j++)
    {
        if(i==0)
        {
            tmat[j][j]=A[j];

        }
        else if(i==1)
        {
            tmat[j][j+i]=max(tmat[j+i][j+i],tmat[j][j]);
            //inner for close
        }//else close
        else
            tmat[j][j+i]=max(A[j]+min(tmat[j+1][j+i-1],tmat[j+2][j+i]),A[j+i]+min(tmat[j][j+i-2],tmat[j+1][j+i-1]));
    }//outer for close


    for(int x=0;x<lenA;x++)
    {
        for(int y=0;y<lenA;y++)
        cout<<" "<<tmat[x][y];
        cout<<endl;
    }
    return tmat[0][lenA-1];
}

int main()
{
    int A[]={5,3,7,10};
    int lenA=sizeof(A)/sizeof(int);
    int ans=fun(A,lenA);
    // 1 and ,2 or,3 xor
    cout<<endl<<ans;
}
