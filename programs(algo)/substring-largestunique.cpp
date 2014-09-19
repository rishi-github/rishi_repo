#include<iostream>
#include<string.h>
using namespace std;

int findmaxunique(char *s)
{
    int len=strlen(s);
    int locinfo[256];
    int res[len];
    res[0]=1;
    for(int i=0;i<256;i++)
        locinfo[i]=-1;
    int currloc=0;
    locinfo[s[0]]=0;
    for(int cur=1;cur<len;cur++)
    {
        if(locinfo[s[cur]]==-1)
            {
                res[cur]=res[cur-1]+1;
                locinfo[s[cur]]=cur;
            }
        else if(locinfo[s[cur]]<currloc)
            {
                locinfo[s[cur]]=cur;
                res[cur]=res[cur-1]+1;
            }

        else if(locinfo[s[cur]]>=currloc)
        {
            res[cur]=cur-locinfo[s[cur]];
            currloc=cur;
            locinfo[s[cur]]=cur;

        }


    }
//for finding maximum in res
int max=-1;
for(int j=0;j<len;j++)
    if(max<res[j])
    max=res[j];
return max;
}

int main()
{
    char s[]="abcaB";
    int r=findmaxunique(s);
    cout<<endl<<r;
}
