#include<iostream>
#include<string.h>
using namespace std;


int fun(int *A,int *B,int lenA,int lenB)
{

    int tmat[lenA][lenA];
    int fmat[lenA][lenA];
    memset(tmat,0,sizeof(tmat));
    memset(fmat,0,sizeof(fmat));
    for(int i=0;i<lenA;i++)
    for(int j=0;j+i<lenA;j++)
    {
        if(i==0)
        {
            tmat[j][j]=A[j];
            fmat[j][j]=A[j]^1;
        }
        else
        {

            for(int k=j;k<i+j;k++)
            {
                if(B[k]==1)//and
                {
                    tmat[j][i+j]=tmat[j][j+i]+(tmat[j][k]*tmat[k+1][j+i]);
                    fmat[j][i+j]=fmat[j][j+i]+((tmat[j][k]+fmat[j][k])*(tmat[k+1][j+i]+fmat[k+1][j+i]))-(tmat[j][j+i]);
                }
                if(B[k]==2)//or
                {
                    fmat[j][i+j]=fmat[j][j+i]+(fmat[j][k]*fmat[k+1][j+i]);
                    tmat[j][i+j]=tmat[j][j+i]+((tmat[j][k]+fmat[j][k])*(tmat[k+1][j+i]+fmat[k+1][j+i]))-(fmat[j][j+i]);

                }
                if(B[k]==3)//xor
                {
                    fmat[j][i+j]=fmat[j][j+i]+(fmat[j][k]*fmat[k+1][j+i])+(tmat[j][k]*tmat[k+1][j+i]);
                    tmat[j][i+j]=tmat[j][j+i]+((tmat[j][k]+fmat[j][k])*(tmat[k+1][j+i]+fmat[k+1][j+i]))-(fmat[j][j+i]);

                }
            }//inner for close
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
    int A[]={1,1,0};
    int B[]={1,2};
    int lenA=sizeof(A)/sizeof(int);
    int lenB=sizeof(B)/sizeof(int);
    int ans=fun(A,B,lenA,lenB);
    // 1 and ,2 or,3 xor
    cout<<endl<<ans;
}

