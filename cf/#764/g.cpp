#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

#define int ll
const int mxn = 5e5 + 10;
int fa[mxn], vis[mxn];

int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) {
    fa[x] = y;
  }
}

struct Edge{
  int u, v, w;
};

void solve()
{
  int n, m; cin >> n >> m;
  vector<Edge> e(m + 5);
  for (int i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) fa[i] = i, vis[i] = 0;
  for (int i = 31; i >= 0; i--) {
    for (int j = 1; j <= n; j++) fa[j] = j;
    for (int j = 1; j <= m; ++j) {
      if (vis[j] || e[j].w >> i & 1) continue;
      merge(e[j].u, e[j].v);
    }
    int cnt = 0;
    for (int j = 1; j <= n; j++) cnt += (fa[j] == j);
    if (cnt == 1) {
      for (int j = 1; j <= m; j++) {
        if (e[j].w >> i & 1) vis[j] = 1;
      }
    }
    else {
      ans |= (1 << i);
    }
  }

  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

