#include<iostream>
using namespace std;
bool var=false;
bool allocate(int *s,int *t,int ssize,int tsize)
{
cout<<endl;
for(int i=0;i<ssize;i++)
{
cout<<s[i]<<"   ";
}

if(tsize==0)
return true;
int flag=false;
for(int i=0;i<ssize;i++)
    {
    if(s[i]>=t[0])
    {
        flag=true;
        s[i]=s[i]-t[0];
        var=var||allocate(s,t+1,ssize,tsize-1);
        s[i]=s[i]+t[0];

    }



    }
if(flag==false)
{
cout<<endl<<false;
return false;}
return var;


}



int main()
{
int s[4]={4,8,7,16};
int t[5]={4,7,7,8,9};
int ssize=sizeof(s)/sizeof(int);
int tsize=sizeof(t)/sizeof(int);


bool res=allocate(s,t,ssize,tsize);
cout<<endl<<res;

}
