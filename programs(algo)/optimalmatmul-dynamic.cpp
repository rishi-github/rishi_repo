
#include<iostream>
#include<string.h>
using namespace std;
#define infinity INT_MAX;

int fun(int *A,int len)
{
int lenA=len-1;
    int tmat[lenA][lenA];
    memset(tmat,0,sizeof(tmat));
    int rmat[lenA][lenA];
    memset(rmat,0,sizeof(rmat));
    int minval=infinity;
    int rem;
    for(int i=0;i<lenA;i++)
    for(int j=0;j+i<lenA;j++)
    {
        if(i==0)
        {
            tmat[j][j]=0;

        }
        else if(i==1)
        {
            tmat[j][j+i]=A[j]*A[j+1]*A[j+2];
            //inner for close
        }//else close
        else
            {
                minval=infinity;
                rem=0;
                for(int k=j;k<j+i;k++)
                {
                    if(minval>tmat[j][k]+tmat[k+1][j+i]+A[j]*A[k+1]*A[j+i+1])
                    {
                        minval=tmat[j][k]+tmat[k+1][j+i]+A[j]*A[k+1]*A[j+i+1];
                        rem=k;
                    }

                }
                tmat[j][j+i]=minval;
                rmat[j][j+i]=rem;
            }
    }//outer for close


    for(int x=0;x<lenA;x++)
    {
        for(int y=0;y<lenA;y++)
        cout<<" "<<tmat[x][y];
        cout<<endl;
    }

    for(int x=0;x<lenA;x++)
    {
        for(int y=0;y<lenA;y++)
        cout<<" "<<rmat[x][y];
        cout<<endl;
    }



    return tmat[0][lenA-1];
}

int main()
{
    int A[]={5,3,7,10,9};
    int lenA=sizeof(A)/sizeof(int);
    int ans=fun(A,lenA);
    // 1 and ,2 or,3 xor
    cout<<endl<<ans;
}

