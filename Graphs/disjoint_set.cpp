#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int ranks[100000];


void makeset(int n)
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

void union_fun(int u,int v)
{
    u=parent_func(u);
    v=parent_func(v);
    if(ranks[u]<ranks[v])
    parent[u]=v;
    else if (ranks[u]>ranks[v])
    parent[v]=u;
    else
    {
        parent[v]=u;
        ranks[u]++;
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    makeset(n);
    int u,v;
    while(m--)
    {
        cin >> u >> v;
        union_fun(u,v);
    }
    int q;
    cin >> q;
    int x,y;
    while(q--)
    {
        cin >> x >> y;
        if(parent_func(x)==parent_func(y))
        cout << "SAME\n";
        else
        cout << "DIFFERENT\n";
    }
    return 0;
}