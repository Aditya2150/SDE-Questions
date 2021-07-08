#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:

// RECURSIVE SOLUTION

// Space- O(dp[][]) Time-O(MV)

	int dp[1001][1001];
	int solve(int coins[], int M, int V,int cnt)
	{
	    if(V<0)
	    return INT_MAX;
	    if(V==0)
	    return cnt;
	    if(dp[V][cnt]!=-1)
	    return dp[V][cnt];
	    int ans=INT_MAX;
	    for(int i=0;i<M;i++)
	    {
	        ans=min(ans,solve(coins,M,V-coins[i],cnt+1));
	    }
	    return dp[V][cnt]=ans;
	}
	
	
	
	int minCoins(int coins[], int M, int V) 
	{
	    memset(dp,-1,sizeof(dp));
	    int x=solve(coins,M,V,0);
	    return (x==INT_MAX?-1:x);
	} 


// DP SOLUTION 

// Time-O(MV) Space-O(V)
    int minCoins(int coins[], int M, int V) 
	{
	    int sum[V+1];
	    for(int i=1;i<=V;i++)
	    sum[i]=INT_MAX;
	    sum[0]=0;
	    for(int i=1;i<=V;i++)
	    {
	        for(int j=0;j<M;j++)
	        {
	            if(coins[j]<=i)
	            sum[i]=min(sum[i],(sum[i-coins[j]]==INT_MAX?INT_MAX:sum[i-coins[j]]+1));
	        }
	    }
	    return (sum[V]==INT_MAX?-1:sum[V]);
	} 
	  
};

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}