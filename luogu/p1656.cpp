#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;

const int mxn = 5e4 + 5;
vector<int> g[mxn];
int cnt = 0;
int dfn[mxn], low[mxn], vis[mxn], ap[mxn];
set<int> nodeAP;
set<pii> bridge;

void tarjan(int u, int fa)
{
  vis[u] = 1;
  low[u] = dfn[u] = ++cnt;
  int child = 0;
  for (int v : g[u])
  {
    if (v == fa) continue;
    if (!dfn[v]) {
      child++;
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (fa != -1 && low[v] >= dfn[u] and !ap[u]) {
        ap[u] = 1;
        nodeAP.insert(u);
      }
      if (low[v] > dfn[u]) {
        if (v < u) bridge.insert({v, u});
        else bridge.insert({u, v});
      }
    }
    else low[u] = min(low[u], dfn[v]);
  }

  if (fa == -1 && child > 1 && !ap[u]) {
    ap[u] = 1;
    nodeAP.insert(u);
  }
}


void solve()
{
#define eb emplace_back
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++)
  {
    cin >> u >> v;
    g[u].eb(v);
    g[v].eb(u);
  }
  for (int i = 1; i <= n; i++)
  {
    if (!dfn[i]) {
      tarjan(i, -1);
    }
  }

  for (auto b : bridge)
  {
    cout << b.first << " " << b.second << endl;
  }
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
