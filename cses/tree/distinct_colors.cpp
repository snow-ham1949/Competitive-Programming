#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mxn = 2e5 + 5;
unordered_set<int> st[mxn];
vector<int> g[mxn];
int color[mxn], res[mxn];

void dfs(int u = 1, int p = 0) {
  for (int v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    if (SZ(st[v]) > SZ(st[u])) swap(st[v], st[u]);
    st[u].insert(st[v].begin(), st[v].end());
  }
  st[u].insert(color[u]);
  res[u] = SZ(st[u]);
}

void solve()
{
  int n; cin >> n;
  for (int i = 1; i <= n; i++) cin >> color[i];
  for (int i = 0, x, y; i < n - 1; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs();
  for (int i = 1; i <= n; i++) cout << res[i] << " \n"[i == n];
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--)
  {
    solve(); 
  }
  return 0;
}

