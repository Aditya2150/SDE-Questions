#include<bits/stdc++.h>
using namespace std;

struct node{
    int u,v,wt;
    node(int U,int V,int weight)
    {
        u=U;
        v=V;
        wt=weight;
    }
};

int main()
{
    int n,m;
    cin >> n >> m;
    vector<node>edges;
    int u,v,wt;
    while(m--)
    {
        cin >> u >> v >> wt;
        edges.push_back(node(u,v,wt));
    }
    vector<int>dist(n+1,100000);
    int src;
    cin >> src;
    dist[src]=0;
    for(int x=0;x<n-1;x++)
    {
        for(auto i:edges)
        {
            if(dist[i.u]+i.wt<dist[i.v])
            dist[i.v]=dist[i.u]+i.wt;
        }
    }
    int f=0;
    for(auto i:edges)
    {
        if(dist[i.u]+i.wt<dist[i.v])
        {
            cout << "NOT POSSIBLE!!!!!\n";
            f=1;
        }
    }
    if(f==0)
    {
        for(auto i:dist)
        cout << i << " ";
        cout << endl;
    }

    return 0;
}