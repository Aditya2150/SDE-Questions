#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int ranks[100000];


bool comp(pair<int,pair<int,int>> x,pair<int,pair<int,int>> y)
{
    return x.first<y.first;
}

void make_set(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        ranks[i]=0;
    }
}

int parent_func(int node)
{
    if(node==parent[node])
        return node;
    return parent[node]=parent_func(parent[node]);    
}


void union_func(int u,int v)
{
    u=parent_func(u);
    v=parent_func(v);
    if(ranks[u]<ranks[v])
    parent[u]=v;
    else if(ranks[u]>ranks[v])
    parent[v]=u;
    else{
        parent[v]=u;
        ranks[u]++;
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    make_set(n);
    int u,v,wt;
    vector<pair<int,pair<int,int>>>edges;
    while(m--)
    {
        cin >> u >> v >> wt;
        edges.emplace_back(make_pair(wt,make_pair(u,v)));
    }
    sort(edges.begin(),edges.end(),comp);
    vector<pair<pair<int,int>,int>>MST;
    int cost=0;
    for(auto edge:edges)
    {
        int u=edge.second.first,v=edge.second.second;
        if(parent_func(u)!=parent_func(v))
        {
            cost+=edge.first;
            union_func(u,v);
            MST.push_back({{u,v},edge.first});
        }
    }
    cout << cost << endl;
    for(auto i:MST)
    cout << i.first.first << " " << i.first.second << " --> " << i.second << endl;
    return 0;
}