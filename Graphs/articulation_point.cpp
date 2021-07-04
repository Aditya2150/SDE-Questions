#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100000];
vector<int>tim(100000);
vector<int>low(100000);
vector<bool>visited(100000,false);

void dfs(int node,int par)
{
    static int cnt=1;
    visited[node]=true;
    tim[node]=low[node]=cnt++;
    int c=0;
    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            dfs(i,node);
            low[node]=min(low[i],low[node]);
            if(low[i]>=tim[node] && par!=-1)
            cout << node << " ";
            c++;
        }
        else if(i!=par)
        low[node]=min(low[node],tim[i]);
    }
    if(par==-1 && c>1)
    cout << node << " ";
    return;
}


int main()
{
    int n,m;
    cin >> n >> m;
    int u,v;
    while(m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    return 0;
}