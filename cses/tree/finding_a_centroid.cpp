#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mxn = 2e5 + 5;
vector<int> g[mxn];
int sz[mxn];
int n;

void dfs(int u = 1, int p = 0) {
  sz[u] = 1;
  for (int v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}

int getCentroid(int u = 1, int p = 0) {
  for (int v : g[u]) {
    if (v == p) continue;
    if (sz[v] * 2 > n) {
      return getCentroid(v, u);
    }
  }
  return u;
}

void solve()
{
  cin >> n;
  for (int i = 0, x, y; i < n - 1; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs();
  cout << getCentroid() << "\n";
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

