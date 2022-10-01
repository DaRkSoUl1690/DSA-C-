#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            findTopoSort(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int n, vector<int> adj[])
{
    stack<int> st;
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            findTopoSort(i, vis, st, adj);
        }
    }
    vector<int> topo;

    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}