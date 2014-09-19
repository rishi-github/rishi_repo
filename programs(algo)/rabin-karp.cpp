
#include<iostream>
using namespace std;
#include<math.h>
#include<string.h>

int mod_util(int a,int b)
{
return (a%b+b)%b;
}
void fun(char *t,char*p,int lt,int lp)
{
int M=23;

//calc hash for pattern
cout<<endl<<mod_util(-4,21);
int b=10;int hp=0;
for(int i=0;i<lp;i++)
{
hp=mod_util(hp*b+p[i],M);

}
//cout<<endl<<hp;
//calc initial hash for text
int pow1=pow(b,lp-1);
int ht=0;
for(int i=0;i<lp;i++)
{
ht=mod_util(ht*b+t[i],M);
}
//cout<<endl<<ht;
int j=0;
while(j<=(lt-lp))
{
if(hp==ht)
{
for(int k=0;k<lp;k++)
if(t[j+k]!=p[k])
break;
cout<<endl<<"position :"<<j;

}
j++;
int temp=mod_util(t[j-1]*pow1,M);
ht=mod_util(ht-temp,M);
ht=mod_util(ht*b,M);
ht=mod_util(ht+t[j+lp-1],M);
cout<<endl<<"sdsa"<<ht;
}



/*for(int j=1;j<=(lt-lp);j++)
{
ht=(ht-t[j-1]*pow1)*b+t[j+lp-1];
//cout<<endl<<ht;
//check linearly
if(ht==hp)
{
for(int k=0;k<lp;k++)
if(t[j+k]!=p[k])
break;
cout<<endl<<"position :"<<j;

}
}*/
//compare hash





}


int main()
{
char text[]="ggggggg";
char pat[]="gg";
int lent=strlen(text);
int lenp=strlen(pat);

fun(text,pat,lent,lenp);

}
