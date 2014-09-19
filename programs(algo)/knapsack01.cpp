#include<iostream>
#include<string.h>
using namespace std;
#define infinity INT_MAX
int knapSack(int W, int *wt, int *val, int n)
{
   // Base Case
   if (W==0)
       return 0;
    else if(n==0)
        return infinity;

   // If weight of the nth item is more than Knapsack capacity W, then
   // this item cannot be included in the optimal solution
   int x,y;
   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);

   // Return the maximum of two cases: (1) nth item included (2) not included
   x=knapSack(W-wt[n-1], wt, val, n-1);
   y=knapSack(W, wt, val, n-1);
   if(x!=infinity && y!=infinity)
   return max(x+val[n-1],y);
   if(x!=infinity)
    return x+val[n-1];
   if(y!=infinity)
        return y;
   return infinity;

}

// Driver program to test above function
int main()
{
    int val[] = {10,20};
    int wt[] = {1,5};
    int  W = 6;
    int n = sizeof(val)/sizeof(val[0]);

    int res=knapSack(W,wt,val,n);
    if(res!=infinity)
        cout<<endl<<res;
    else
        cout<<endl<<"not possible";
}
