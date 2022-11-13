#include <bits/stdc++.h>
 
#define AC                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long
#define pli pair<long long, int>
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define inf 1e18
 
using namespace std;
 
// #define DEBUG
 
int main()
{
    AC;
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll> > dis(n + 1, vector<ll>(n + 1, inf));
    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        dis[s][e] = min(dis[s][e], (ll)w);
        dis[e][s] = dis[s][e];
    }
 
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == k) continue;
            for (int j = i + 1; j <= n; j++)
            {
                if (j == k) continue;
                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    dis[j][i] = dis[i][j];
                }
            }
        }
    }
#ifdef  DEBUG
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << "\n";
    }
#endif  //DEBUG
 
 
 
    while (q--)
    {
        int s, e;
        cin >> s >> e;
        if (dis[s][e] == inf)
        {
            cout << "-1\n";
        }
        else
        {
            cout << dis[s][e] << "\n";
        }
    }
 
    return 0;
}

