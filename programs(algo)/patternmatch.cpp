
#include<iostream>
using namespace std;
void naive_pattern_match(char*,char*,int ,int);

int main()
{
char txt[]="eeeee";
char pattern[]="ew";
int n=sizeof(txt)/sizeof(txt[0]);
//cout<<n;
int m=sizeof(pattern)/sizeof(pattern[0]);
naive_pattern_match(txt,pattern,n-1,m-1);



}
void naive_pattern_match(char * txt,char *pat,int n,int m)
{
bool flag=false;
for(int i=0;i<(n-m+1);i++)
{
flag=false;
for(int j=0;j<m;j++)
    if(pat[j]!=txt[i+j])
    {
        flag=true;
        break;


    }
    if(!flag)
        cout<<"pattern found at position "<<i;

}
}
