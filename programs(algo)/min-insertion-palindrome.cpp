#include<iostream>


#include<string.h>
#include<math.h>
using namespace std;


int fun(char *A,int lenA)
{

    int tmat[lenA][lenA];
    memset(tmat,0,sizeof(tmat));

    for(int i=0;i<lenA;i++)
    for(int j=0;j+i<lenA;j++)
    {
        if(i==0)
        {
            tmat[j][j]=0;
        }
        else
        {
            if(A[j]==A[j+i])
                tmat[j][j+i]=tmat[j+1][j+i-1];
            else
                tmat[j][j+i]=1+min(tmat[j+1][j+i],tmat[j][j+i-1]);

        }//else close
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

    char A[]="ardmandr";

    int lenA=(sizeof(A)-1)/sizeof(char);

    int ans=fun(A,lenA);
    // 1 and ,2 or,3 xor
    cout<<endl<<ans;
}

