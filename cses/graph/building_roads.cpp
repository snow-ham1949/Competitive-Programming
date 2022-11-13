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
    vector<int> vis(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }
 
    int connect = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == -1)
        {
            vector<int> v;
            queue<int> q;
            q.push(i);
            vis[i] = connect;
            v.push_back(i);
            while (!q.empty())
            {
                int c = q.front();
                q.pop();
                for (int adj : g[c])
                {
                    if (vis[adj] == -1)
                    {
                        q.push(adj);
                        v.push_back(adj);
                        vis[adj] = connect;
                    }
                }
            }
            connectCity.push_back(v);
            connect++;
        }
    }
    cout << connect - 1 << "\n";
#ifdef DEBUG
    for (int i = 0; i < connect; i++)
    {
        cout << i << ": ";
        for (int city : connectCity[i])
        {
            cout << city << " ";
        }
        cout << "\n";
    }
    cout << "\n";
#endif
    for (int i = 0; i < connect - 1; i++)
    {
        cout << connectCity[i][0] << " " << connectCity[i + 1][0] << "\n";
    }
    return 0;
}
