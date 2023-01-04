#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

struct BIT {
  int n;
  vector<ll> bit;
  BIT (int _n) : n(_n), bit(_n + 1) {};
  #define lowbit(x) (x) & (-x)
  void add(int x, ll val) {
    while (x <= n) {
      bit[x] += val;
      x += lowbit(x);
    }
  }
  ll query(int x) {
    ll res = 0;
    while (x) {
      res += (ll)(bit[x]);
      x -= lowbit(x);
    }
    return res;
  }
};

const int mxn = 2e5 + 5;
vector<int> g[mxn];
int st[mxn], ed[mxn], timer;
void dfs(int u = 1, int p = 0) {
  st[u] = ++timer;
  for (int v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  ed[u] = timer;
}

ll val[mxn];

void solve()
{
  int n, q; 
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> val[i];
  for (int i = 0, x, y; i < n - 1; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs();
  BIT tr(n);
  for (int i = 1; i <= n; i++) {
    tr.add(st[i], val[i]);
    tr.add(ed[i] + 1, -val[i]);
  }
  int op, s;
  ll x;
  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> s >> x;
      tr.add(st[s], x - val[s]);
      tr.add(ed[s] + 1, - (x - val[s]));
      val[s] = x;
    }
    else {
      cin >> s;
      cout << tr.query(st[s]) << "\n";
    }
  }
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

