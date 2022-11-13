#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 100 + 5;
const ll inf = 1e18;

ll dis[mxn][mxn], mp[mxn][mxn];

void solve()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i != j) dis[i][j] = mp[i][j] = inf;
    }
  }
  for (int i = 0,  u, v, w; i < m; i++)
  {
    cin >> u >> v >> w;
    dis[v][u] = dis[u][v] = min(dis[u][v], (ll)w);
    mp[v][u] = mp[u][v] = min(mp[u][v], (ll)w);
    
  }

  ll ans = inf;
  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i < k; i++)
    {
      for (int j = i + 1; j < k; j++)
      {
        ans = min(ans, dis[i][j] + mp[i][k] + mp[k][j]);
      }
    }
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }

  if (ans == inf) cout << "No solution.\n";
  else cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

