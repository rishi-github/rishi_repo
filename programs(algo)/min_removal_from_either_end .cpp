#include<iostream>
using namespace std;
int min,max;


bool is2mingmax(int * arr,int i,int j)
{
    if(i==j)
        return true;
    int mi,mx;
    mi=mx=arr[i];
    for(int k=i+1;k<=j;k++)
    {
        if(arr[k]<mi)
            mi=arr[k];
        else if(arr[k]>mx)
            mx=arr[k];


    }
    if(2*mi>mx)
        return true;
    else
        return false;

}

int recurse(int *ptr,int i,int j)
{
    if(is2mingmax(ptr,i,j))
        return 0;
    else
        {

            return 1+min(recurse(ptr,i+1,j),recurse(ptr,i,j-1));

        }

}

void dynamic_minremoval(int *arr,int n)
{
int mat[n][n];

for(int i=0;i<n;i++)
mat[i][i]=0;

min=0;
max=arr[1];
for(int i=1;i<n;i++)
for(int j=0,k=i;k<n;j++,k++)
{

if(is2mingmax(arr,j,k))
    mat[j][k]=0;
else
    mat[j][k]=1+min(mat[j+1][k],mat[j][k-1]);


}
cout<<endl<<"min removal   "<<mat[0][8];

}



int main()
{
    int arr[]={4,5,100,9,10,11,12,15,200};
    int rem_ele[sizeof(arr)/sizeof(int)];
    //recurse(arr);
    //cout<<"the minimum removals are:";
    //int res=recurse(arr,0,8);
    //cout<<endl<<res;
    dynamic_minremoval(arr,9);


    //cout<<endl<<"and the removed elements are:    ";
    //for(int i=0;i<res;i++)
    //cout<<rem_ele[i]<<" ";
}

