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

ll bit[mxn];
int n, q;

int lowbit(int x) {
  return x & (-x);
}

void update(int i, int x) {
  for (; i <= n; i += lowbit(i)) bit[i] += x;
}

ll query(int pos) {
  ll sum = 0;
  for (int i = pos; i > 0; i -= lowbit(i)) sum += bit[i];
  return sum;
}

int st[mxn], ed[mxn], val[mxn];
int timer;

void dfs(int u = 1, int p = 0) {
  st[u] = ++timer;
  for (int v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  ed[u] = timer;
}

void solve()
{
#define eb emplace_back
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> val[i];
  for (int i = 0, x, y; i < n - 1; i++) {
    cin >> x >> y;
    g[x].eb(y);
    g[y].eb(x);
  }
  dfs();
  for (int i = 1; i <= n; i++) update(st[i], val[i]);
  int op, s, x;
  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> s >> x;
      update(st[s], x - val[s]);
      val[s] = x;
    }
    else {
      cin >> s;
      cout << query(ed[s]) - query(st[s] - 1) << endl;
    }
  }
}

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

