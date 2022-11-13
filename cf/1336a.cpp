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
int n, k;
#define eb emplace_back

int dep[mxn];

void dfs(int u = 1, int p = 0, int d = 0) {
  dep[u] = d;
  for (int v : g[u]) {
    if (v == p) continue;
    dfs(v, u, d + 1);
  }
}

void solve()
{
  cin >> n >> k;
  for (int i = 1, u, v; i <= n - 1; i++) {
    cin >> u >> v;
    g[u].eb(v);
    g[v].eb(u);
  }

  // k industry, (n - k) tourism
  dfs();

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

