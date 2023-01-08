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
int vis[mxn], ans;

void dfs(int u = 1) {
  for (int v : g[u]) {
    if (!vis[v]) {
      vis[v] = 1;
      ans++;
      if (ans >= 1000000) {
        ans = 1000000;
        return;
      }
      dfs(v);
      vis[v] = 0;
    }
  }
}

void solve()
{
  int n, m; cin >> n >> m;
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vis[1] = 1;
  ans++;
  dfs();
  cout << ans << "\n";
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

