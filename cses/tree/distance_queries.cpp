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

int st[mxn][21], dep[mxn];
vector<int> g[mxn];
int n;

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

void solve()
{
#define eb emplace_back
  int q;
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
    // find lca
    cin >> a >> b;
    if (dep[a] < dep[b]) swap(a, b);
    int diff = dep[a] - dep[b], res = dep[a] + dep[b];
    for (int i = 20; i >= 0; i--) {
      if (diff & (1 << i)) a = st[a][i];
    }
    if (a == b) {
      cout << diff << endl;
    }
    else {
      for (int i = 20; i >= 0; i--) {
        if (st[a][i] != st[b][i]) {
          a = st[a][i];
          b = st[b][i];
        }
      }
      cout << res - 2 * dep[st[a][0]] << endl;
    }
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

