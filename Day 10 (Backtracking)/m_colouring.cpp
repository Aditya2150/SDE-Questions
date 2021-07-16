#include <bits/stdc++.h>
using namespace std;

bool issafe(int node,int V,bool graph[101][101],vector<int>& color,int i)
{
    for(int j=0;j<V;j++)
    {
        if(graph[node][j]==1 && color[j]==i)
        return false;
    }
    return true;
}

bool solve(bool graph[101][101], int m, int V,vector<int> color,int x)
{
    if(x==V)
    return true;
    for(int i=1;i<=m;i++)
    {
        if(issafe(x,V,graph,color,i))
        {
            color[x]=i;
            if(solve(graph,m,V,color,x+1))
            return true;
            color[x]=0;
        }
    }
    return false;
}


bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int>color(V,0);
    return solve(graph,m,V,color,0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}