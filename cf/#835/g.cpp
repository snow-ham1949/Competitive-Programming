#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

#define eb emplace_back
const int mxn = 1e5 + 5;
vector<pii> g[mxn];
int n, a, b;
set<int> st;

void dfs1(int u, int p, int x) {
  for (auto [v, w] : g[u]) {
    if (v != p) {
      st.insert(x ^ w);
      dfs1(v, u, x ^ w);
    }
  }
}

bool dfs2(int u, int p, int x) {
  if (st.find(x) != st.end()) return 1;
  for (auto [v, w] : g[u]) {
    if (v != p && v != b) {
      if (dfs2(v, u, x ^ w)) return 1;
    }
  }
  return 0;
}

void solve()
{
  cin >> n >> a >> b; 
  for (int i = 0, u, v, w; i < n - 1; i++) {
    cin >> u >> v >> w;
    g[u].eb(v, w);
    g[v].eb(u, w);
  }
  dfs1(b, 0, 0);
  if (dfs2(a, 0, 0)) cout << "YES\n";
  else cout << "NO\n";
  for (int i = 1; i <= n; i++) g[i].clear();
  st.clear();
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}
