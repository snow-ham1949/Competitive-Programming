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
 
int len = INT_MAX;
vector<char> ans;
 
int d[5] = {0, -1, 0, 1, 0};
char dir[4] = {'L', 'U', 'R', 'D'};
 
int main()
{
    AC;
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<int>> prevStep(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    pair<int, int> src, des;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
            {
                src = mp(i, j);
            }
            if (g[i][j] == 'B')
            {
                des = mp(i, j);
            }
        }
    }
 
    vis[src.F][src.S] = true;
 
    queue<pii> q;
    q.push(src);
    while (!q.empty())
    {
        pii p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pii tmp = mp(p.F + d[i], p.S + d[i + 1]);
            if (tmp.F < 0 or tmp.F >= n or tmp.S < 0 or tmp.S >= m)
            {
                continue;
            }
 
            if (vis[tmp.F][tmp.S])
            {
                continue;
            }
 
            if (g[tmp.F][tmp.S] == '#')
            {
                continue;
            }
            vis[tmp.F][tmp.S] = true;
            q.push(tmp);
            prevStep[tmp.F][tmp.S] = i;
        }
    }
    if (vis[des.F][des.S])
    {
        cout << "YES\n";
        vector<int> step;
        while (des != src)
        {
            int direction = prevStep[des.F][des.S];
            step.push_back(direction);
            des = mp(des.F - d[direction], des.S - d[direction + 1]);
        }
 
        reverse(step.begin(), step.end());
 
        cout << step.size() << "\n";
        for (int s : step)
        {
            cout << dir[s];
        }
    }
    else
    {
        cout << "NO\n";
    }
    
 
    return 0;
}
