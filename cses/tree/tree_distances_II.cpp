// ref: https://usaco.guide/problems/cses-1133-tree-distances-ii/solution
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()

const int mxn = 2e5 + 5;

vector<int> g[mxn];
ll sz[mxn], ans[mxn], n;

void dfs1(int u = 1, int p = 0, int dep = 0) {
  ans[1] += dep;
  sz[u]++;
  for (int v : g[u]) {
    if (v == p) continue;
    dfs1(v, u, dep + 1);
    sz[u] += sz[v];
  }
}

void dfs2(int u = 1, int p = 0) {
  for (int v : g[u]) {
    if (v == p) continue;
    ans[v] = ans[u] + (n - sz[v]) - sz[v];
    dfs2(v, u);
  }
}

void solve()
{
#define eb emplace_back
  cin >> n;
  for (int i = 0, x, y; i < n - 1; i++) {
    cin >> x >> y;
    g[x].eb(y);
    g[y].eb(x);
  }
  dfs1();
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

