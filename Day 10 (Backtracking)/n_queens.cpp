// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// RECURSION
class Solution{
    
    int dp[10][10];
    
public:

    bool check(int r,int c,int n)
    {
        // Left Diagonal
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
        {
            if(dp[i][j])
            return true; 
        }
        // Up
        for(int i=r-1;i>=0;i--)
        {
            if(dp[i][c])
            return true; 
        }
        // Right Diagonal
        for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++)
        {
            if(dp[i][j])
            return true; 
        }
        return false;
    }

    void solve(int n,int r,vector<int>v,vector<vector<int>>& ans)
    {
        if(r==n)
        {
            ans.push_back(v);
            return;
        }
        for(int c=0;c<n;c++)
        {
            if(!check(r,c,n))
            {
                v.push_back(c+1);
                dp[r][c]=true;
                solve(n,r+1,v,ans);
                dp[r][c]=false;
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        if(n==1)
        return vector<vector<int>>{vector<int>{1}};
        vector<vector<int>> ans;
        if(n==2 || n==3)
        return ans;
        vector<int>v;
        memset(dp,false,sizeof(dp));
        solve(n,0,v,ans);
        return ans;
    }
};


// BRANCH & BOUND

class Solution{

    bool up[10];
    bool left_diag[19];
    bool right_diag[19];
public:


    void solve(int n,int r,vector<int>v,vector<vector<int>>& ans)
    {
        if(r==n)
        {
            ans.push_back(v);
            return;
        }
        for(int c=0;c<n;c++)
        {
            if(!up[c] && !left_diag[r+c] && !right_diag[r-c+n-1])
            {
                v.push_back(c+1);
                up[c]=true;
                left_diag[r+c]=true;
                right_diag[r-c+n-1]=true;
                solve(n,r+1,v,ans);
                up[c]=false;
                left_diag[r+c]=false;
                right_diag[r-c+n-1]=false;
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        if(n==1)
        return vector<vector<int>>{vector<int>{1}};
        vector<vector<int>> ans;
        if(n==2 || n==3)
        return ans;
        vector<int>v;
        memset(up,false,sizeof(up));
        memset(left_diag,false,sizeof(left_diag));
        memset(right_diag,false,sizeof(right_diag));
        solve(n,0,v,ans);
        return ans;
    }
};




int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}