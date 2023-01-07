#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mxn = 100 + 5;
vector<int> g[mxn];
int vis[mxn];

void dfs(int u, int p = 0) {
  for (int v : g[u]) {
    if (v == p) continue;
    if (!vis[v]) {
      vis[v] = 1;
      dfs(v, u);
    }
  }
}

void solve()
{
  int n, m; cin >> n >> m;  
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      res++;
      dfs(i);
    }
  }
  cout << res << "\n";
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

