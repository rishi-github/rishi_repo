#include<iostream>
using namespace std;
#define rad 10
void radixsort(int arr[],int,int []);
int find_max(int [],int);
int main()
{
int arr[]={9999,142,22,56,12,45,12,65,999,123,121,122,120};
int size=sizeof(arr)/sizeof(arr[0]);
//cout<<size;
int output[size];
radixsort(arr,size,output);
for(int i=0;i<size;i++)
cout<<output[i]<<'\n';


}
int find_max(int arr[],int size)
{int max=-1;
for(int j=0;j<size;j++)
{
if(max<arr[j])
max=arr[j];

}
return max;
}


void radixsort(int arr[],int size,int output[])
{

int count[rad]={0};

//output[size];
int max=find_max(arr,size);
int val=max;
int div=1;
while((val/div)%rad)
{
for(int i=0;i<rad;i++)
count[i]=0;
for(int i=0;i<size;i++)
{
count[(arr[i]/div)%rad]++;
}
//find aggregate val of count
for(int i=1;i<rad;i++)
{
count[i]=count[i]+count[i-1];
}
//for(int i=0;i<rad;i++)
//cout<<count[i]<<" ";
//cout<<'\n';
for(int i=size-1;i!=-1;i--)
{
output[count[(arr[i]/div)%rad]-1]=arr[i];
count[(arr[i]/div)%rad]--;
}
//for(int i=0;i<size;i++)
//cout<<output[i]<<" ";
//cout<<'\n';
for(int i=0;i<size;i++)
arr[i]=output[i];
div=div*rad;
}
}
