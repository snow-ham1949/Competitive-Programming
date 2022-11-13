#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 2e5 + 5;

vector<int> g[mxn];
int dep[mxn], ans[mxn], st[mxn][21];
int n, q;

void dfs(int u = 1, int p = 0, int d = 0) {
  st[u][0] = p;
  dep[u] = d;
  for (int v : g[u]) {
    if (v == p) continue;
    dfs(v, u, d + 1);
  }
}

void init() {
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

void dfs2(int u = 1, int p = 0) {
  for (int v : g[u]) {
    if (v == p) continue;
    dfs2(v, u);
    ans[u] += ans[v];
  }
}

void solve()
{
#define eb emplace_back
  cin >> n >> q;
  for (int i = 0, x, y; i < n - 1; i++) {
    cin >> x >> y;
    g[x].eb(y);
    g[y].eb(x);
  }
  dfs();
  init();
  int a, b;
  while (q--) {
    cin >> a >> b;
    ans[a]++;
    ans[b]++;
    ans[st[LCA(a, b)][0]]--;
    ans[LCA(a, b)]--;
  }
  dfs2();
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << endl;
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

