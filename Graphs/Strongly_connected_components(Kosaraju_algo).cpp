#include<bits/stdc++.h>
using namespace std;

bool visited[100000];
vector<int>adj[100000];
vector<int>transpose[100000];


void dfs(int node,stack<int>& s)
{
    visited[node]=true;
    for(auto i:adj[node])
    {
        if(!visited[i])
        dfs(i,s);
    }
    s.push(node);
    return;
}

void rev_dfs(int node)
{
    cout << node << " ";
    visited[node]=true;
    for(auto i:transpose[node])
    {
        if(!visited[i])
        rev_dfs(i);
    }
    return;
}

int main()
{
    int n,m;
    cin >> n >> m;
    memset(visited,false,sizeof(visited));
    int u,v;
    while(m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    stack<int>s;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        dfs(i,s);
    }
    for(int i=1;i<=n;i++)
    {
        visited[i]=false;
        for(auto x:adj[i])
        transpose[x].push_back(i);
    }
    cout << "Strongly Connected Components are-\n";
    while(!s.empty())
    {
        int i=s.top();
        s.pop();
        if(!visited[i])
        {
            cout << "-> ";
            rev_dfs(i);
            cout << endl;
        }
    }
    return 0;
}