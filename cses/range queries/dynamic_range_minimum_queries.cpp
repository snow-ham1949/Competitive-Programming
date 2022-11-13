#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 2e5 + 5;

int seg[4 * mxn], a[mxn];

void pull(int id)
{
  seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
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

void update(int p, int v, int l, int r, int id = 1)
{
  if (p < l || r < p) return;
  if (l == r) {
    seg[id] = v;
    return;
  }
  int m = (l + r) >> 1;
  update(p, v, l, m, id * 2);
  update(p, v, m + 1, r, id * 2 + 1);
  pull(id);
}

int query(int ql, int qr, int l, int r, int id = 1)
{
  if (qr < l || r < ql) {
    // fprintf(stderr, "Case #1, l: %d, r: %d\n", l, r);
    return INT_MAX;
  }
  if (ql <= l && r <= qr) {
    // fprintf(stderr, "Case #2, l: %d, r: %d, seg[%d]: %d\n", l, r, id, seg[id]);
    return seg[id];
  }
  int m = (l + r) >> 1;
  return min(query(ql, qr, l, m, id * 2), query(ql, qr, m + 1, r, id * 2 + 1));
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
      int k, v;
      cin >> k >> v;
      update(k, v, 1, n);
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

