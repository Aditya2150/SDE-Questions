#include<bits/stdc++.h> 
using namespace std; 

class Solution{ 
public:
    int solve(int n, int arr[], int sum,int dp[][101])
    {
        if(sum==0)
            return 1;
        if(sum<0 || n<0)
            return 0;
        if(dp[sum][n]!=-1) 
            return dp[sum][n];
        return dp[sum][n]=(solve(n-1,arr,sum-arr[n],dp) || solve(n-1,arr,sum,dp));
    }
    bool isSubsetSum(int N, int arr[], int sum){
        int dp[sum+1][101];
        memset(dp,-1,sizeof(dp));
        return (solve(N-1,arr,sum,dp)==1?true:false);
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
}