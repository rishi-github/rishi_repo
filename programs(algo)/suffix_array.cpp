#include<iostream>
#include<string.h>
using namespace std;


void do_suffix(char ** suffix,int *track,int size)
{
int count=0;
char *temp;int t;
for(int i=0;i<size;i++)
{for(int j=i+1;j<size;j++)
{
if(strcmp(suffix[i],suffix[j]))
{count++;
temp=suffix[i];
suffix[i]=suffix[j];
suffix[j]=temp;
t=track[i];
track[i]=track[j];
track[j]=t;

}
}
cout<<endl;
for(int k=0;k<size;k++)
cout<<"   "<<suffix[k];

}
}

void suffix_array(char* A,int size)
{
char * suffix[size];
int track[size];

for(int i=0;i<size;i++)
{
suffix[i]=A+i;
track[i]=i;
}
do_suffix(suffix,track,size);
for(int i=0;i<size;i++)
{
cout<<endl<<suffix[i];
//cout<<track[i];
}
for(int i=0;i<size;i++)
{
//cout<<suffix[i];
cout<<track[i];
}
}



int main()
{
char A[]="banana$";//$ is added as the ascii value of $ is lesser than our character set
int size=strlen(A);
//suffix_array(A,size);
cout<<strcmp("banana","anana");



}
