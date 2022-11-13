#include <bits/stdc++.h>
 
#define AC                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
 
using namespace std;
 
int d[5] = {0, -1, 0, 1, 0};
 
// #define DEBUG
 
int main()
{
    AC;
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            vis[i][j] = (c == '#');
        }
    }
 
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                queue<pair<int, int>> q;
                pair<int, int> src(i, j);
                q.push(src);
                vis[i][j] = true;
#ifdef DEBUG
                cout << src.first << " " << src.second << "\n";
#endif
                while (!q.empty())
                {
                    pair<int, int> p = q.front();
                    q.pop();
#ifdef DEBUG
                    cout << p.first << " " << p.second << "\n";
#endif
                    for (int k = 0; k < 4; k++)
                    {
                        pair<int, int> tmp(p.first + d[k], p.second + d[k + 1]);
                        if (tmp.first >= 0 and tmp.first < n and tmp.second >= 0 and tmp.second < m and !vis[tmp.first][tmp.second])
                        {
                            q.push(tmp);
                            vis[tmp.first][tmp.second] = true;
                        }
                    }
                }
                ans++;
            }
        }
    }
 
    cout << ans << "\n";
}
