#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100000];
vector<int>visited(100000,-1);


bool check(int n)
{
    queue<int>q;
    q.push(n);
    visited[n]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto i:adj[node])
        {
            if(visited[i]==-1)
            {
                q.push(i);
                visited[i]=1-visited[node];
            }
            else if(visited[i]==visited[node])
            return false;
        }
    }
    return true;
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
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==-1)
        {
            if(!check(i))
            {
                cout << "NOT a BIPARTITE!!!!\n";
                return 0;
            } 
        }
    }
    cout <<"BIPARTITE GRAPH......\n";
    return 0;
}