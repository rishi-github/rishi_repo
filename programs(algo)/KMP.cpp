
#include<iostream>
using namespace std;
#include<math.h>
#include<string.h>

void KMP(char* A,int n,int *track)
{
int j=1;
int i=0;
int count=0;
//int track[n];
track[0]=-1;
//track[1]=0;

while(j<n)
{
if(A[i]!=A[j])
{
//cout<<endl<<count;
i=0;
count=0;

}
if(A[i]==A[j])
{
count++;
i++;

}
track[j]=count;
j++;
}
for(int i=0;i<n;i++)
cout<<endl<<track[i];
}

void fun_kmp(char *text,char *pat,int lt,int lp)
{
int track[lp];
KMP(pat,lp,track);
int j=0,i=0;
while(i<lt)
{
if(pat[j]==text[i])
{
i++;
j++;
}
else if(j!=0)
j=track[j];
else
i++;
}

}

int main()
{
char text[]="ABABDABACDABABCABAB";
char arr[]="ABABCABAB";
int lenp=strlen(arr);
int lent=strlen(text);
fun_kmp(text,arr,lent,lenp);



}
