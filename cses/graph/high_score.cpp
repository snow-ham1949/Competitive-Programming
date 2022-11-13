#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 2500 + 5;

struct Edge {
  int u, v;
  ll w;
};

vector<int> g[mxn], gr[mxn];
int vis[mxn], visr[mxn];

void dfs(int u)
{
  vis[u] = 1;
  for (int v : g[u])
  {
    if (!vis[v]) dfs(v);
  }
}

void dfsr(int u)
{
  visr[u] = 1;
  for (int v : gr[u])
  {
    if (!visr[v]) dfsr(v);
  }
}

void solve()
{
  int n, m; 
  cin >> n >> m;
  vector<tuple<int, int, int>> edge;
  for (int i = 0, u, v, w; i < m; i++)
  {
    #define pb push_back
    cin >> u >> v >> w;
    w *= -1;
    edge.pb({u, v, w});
    g[u].pb(v);
    gr[v].pb(u);
  }
  dfs(1), dfsr(n);

  // bellman ford
  vector<ll> dist(n + 1, 1e16);
  dist[1] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (auto [u, v, w] : edge)
    {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        if (i == n && vis[v] && visr[v]) {
          cout << "-1\n";
          return;
        }
      }
    }
  }
  cout << -dist[n] << endl;
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

