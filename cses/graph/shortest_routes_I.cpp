#include <bits/stdc++.h>
 
#define AC                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define pli pair<long long, int>
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
 
using namespace std;
 
// #define DEBUG
 
int main()
{
    AC;
    int n, m;
    cin >> n >> m;
    vector<vector<pli>> adj(n + 1, vector<pli>());
    for (int i = 0; i < m; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        adj[s].push_back({e, w});
    }
    vector<long long> dis(n + 1, LLONG_MAX);
    vector<int> vis(n + 1, 0);
    dis[1] = 0;
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int u = pq.top().S;
        pq.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;
        for (auto [v, w] : adj[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
 
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
 
 
 
    return 0;
}

