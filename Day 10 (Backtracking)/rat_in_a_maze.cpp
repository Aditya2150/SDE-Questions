#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool visited[6][6];
    int x[4]={-1,0,1,0};
    int y[4]={0,-1,0,1};
    string dir="ULDR";
    
    bool valid(int a,int b,int n)
    {
        return a>=0 && a<n && b>=0 && b<n && !visited[a][b];
    }
    
    void solve(int i,int j,vector<vector<int>> &m, int n,string s,vector<string>& ans)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(s);
            return;
        }
        for(int k=0;k<4;k++)
        {
            int a=x[k]+i,b=y[k]+j;
            if(valid(a,b,n) && m[a][b]==1)
            {
                s+=dir[k];
                visited[a][b]=true;
                solve(a,b,m,n,s,ans);
                visited[a][b]=false;
                s.pop_back();
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        memset(visited,false,sizeof(visited));
        vector<string>ans;
        string s;
        if(m[0][0]==0)
        return ans;
        visited[0][0]=true;
        solve(0,0,m,n,s,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} 