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
 
void dfs(int id, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &col, int color)
{
    vis[id] = true;
    col[id] = color;
    for (int nei : adj[id])
    {
        if (!vis[nei])
        {
            if (color == 1)
            {
                dfs(nei, adj, vis, col, 2);
            }
            else
            {
                dfs(nei, adj, vis, col, 1);
            }
        }
    }
}
 
int main()
{
    AC;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<bool> vis(n + 1, false);
    vector<int> col(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
 
    int color = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, col, color);
        }
    }
 
    bool flag = 1;
 
    for (int i = 1; i <= n; i++)
    {
        for (int nei : adj[i])
        {
            if (col[nei] == col[i])
            {
                flag = 0;
                break;
            }
        }
    }
 
    if (!flag)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << col[i] << " ";
        }
    }
 
    return 0;
}
