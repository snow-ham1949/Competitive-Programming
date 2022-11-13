#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()

const int mxn = 2e5 + 5;

vector<int> g[mxn];
int st[mxn][21];
int dep[mxn], n, q;

void dfs(int u = 1, int p = -1, int d = 0) {
  st[u][0] = p;
  dep[u] = d;
  for (int v : g[u]) {
    if (v == p) continue;
    dfs(v, u, d + 1);
  }
}

void init() {
  dfs();
  for (int i = 1; (1 << i) <= n; i++) {
    for (int j = 1; j <= n; j++) {
      st[j][i] = st[st[j][i - 1]][i - 1];
    }
  }
}

int LCA(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int diff = dep[u] - dep[v];
  for (int i = 20; i >= 0; i--) {
    if (diff & (1 << i)) {
      u = st[u][i];
    }
  }
  if (u == v) return u;
  for (int i = 20; i >= 0; i--) {
    if (st[u][i] != st[v][i]) {
      u = st[u][i];
      v = st[v][i];
    }
  }

  return st[u][0];
}

void solve()
{
#define eb emplace_back
  cin >> n >> q;
  for (int i = 2, p; i <= n; i++) {
    cin >> p;
    g[i].eb(p);
    g[p].eb(i);
  }
  init();
  int u, v;
  while (q--) {
    cin >> u >> v;
    cout << LCA(u, v) << endl;
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

