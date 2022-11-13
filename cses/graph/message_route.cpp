#include <bits/stdc++.h>
 
#define AC                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define pii pair<int, int>
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
    vector<vector<int>> g(n + 1, vector<int>()), connectCity;
    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, -1), dist(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }
 
    int src = 1, des = n;
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dist[src] = 1;
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        for (int adj : g[c])
        {
            if (!vis[adj])
            {
                parent[adj] = c;
                vis[adj] = true;
                q.push(adj);
                dist[adj] = dist[c] + 1;
            }
        }
    }
 
#ifdef DEBUG
    for (int p : parent)
    {
        cout << p << " ";
    }
    cout << "\n";
#endif
 
    if (!vis[des])
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << dist[des] << "\n";
        vector<int> path;
        while (des != 1)
        {
            path.push_back(des);
            des = parent[des];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
 
        for (int c : path)
        {
            cout << c << " ";
        }
    }
    return 0;
}

