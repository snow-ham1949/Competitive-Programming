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
 
#define DEBUG
 
void dfs(int id, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &path, int parent)
{
    vis[id] = true;
    path.push_back(id);
    for (int nei : adj[id])
    {
        if (nei == parent)
        {
            continue;
        }
 
        if (vis[nei])
        {
            path.push_back(nei);
            int sz = path.size(), pos = -1;
            for (int i = 0; i < sz - 1; i++)
            {
                if (path[i] == nei)
                {
                    pos = i;
                    break;
                }
            }
            cout << sz - pos << "\n";
            for (int i = pos; i < sz; i++)
            {
                cout << path[i] << " ";
            }
            exit(0);
        }
 
        dfs(nei, adj, vis, path, id);
    }
    path.pop_back();
}
 
int main()
{
    AC;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<bool> vis(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
 
    bool first = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vector<int> path;
            dfs(i, adj, vis, path, 0);
        }
    }
 
    cout << "IMPOSSIBLE\n";
 
    return 0;
}
