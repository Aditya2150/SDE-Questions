#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>adj[100000];

int main()
{
    int n,m;
    cin >> n >> m;
    int u,v,wt;
    while(m--)
    {
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>mst(n+1,0);
    vector<int>par(n+1,-1);
    vector<int>key(n+1,INT_MAX);
    key[1]=0;
    pq.push(make_pair(0,1));
    for(int cnt=1;cnt<n;cnt++)
    {
        int node=pq.top().second;
        pq.pop();
        mst[node]=1;
        for(auto i:adj[node])
        {
            int next=i.first;
            int wt=i.second;
            if(!mst[next] && key[next]>wt)
            {
                par[next]=node;
                key[next]=wt;
                pq.push(make_pair(key[next],next));
                
            }
        }
    }
    for(int i=0;i<=n;i++)
        cout<< par[i] << " ";
    return 0;
}