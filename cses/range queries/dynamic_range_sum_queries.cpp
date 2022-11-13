#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 2e5 + 5;

ll a[mxn], seg[4 * mxn];

void pull(int id)
{
  seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

void build(int l, int r, int id = 1)
{
  if (l == r) {
    seg[id] = a[l];
    return;
  }
  int m = (l + r) >> 1;
  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);
  pull(id);
}

ll query(int ql, int qr, int l, int r, int id = 1)
{
  if (qr < l || ql > r) return 0;
  if (ql <= l && r <= qr) return seg[id];
  int m = (l + r) >> 1;
  return query(ql, qr, l, m, id * 2) + query(ql, qr, m + 1, r, id * 2 + 1);
}

void update(int p, ll v, int l, int r, int id = 1)
{
  if (p < l || r < p) return;
  if (l == r) {
    seg[id] = v;
    return;
  }
  int m = (l + r) >> 1;
  update(p, v, l, m, 2 * id);
  update(p, v, m + 1, r, 2 * id + 1);
  pull(id);
}

void solve()
{
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, n);
  while (q--)
  {
    int op;
    cin >> op;
    if (op == 1) {
      int k;
      ll u;
      cin >> k >> u;
      update(k, u, 1, n);
    } else {
      int ql, qr;
      cin >> ql >> qr;
      cout << query(ql, qr, 1, n) << endl;
    }
  }
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

