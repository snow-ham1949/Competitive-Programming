#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 1e6;

int seg[mxn << 2], a[mxn];

void pullup(int id) {
  seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}

void build(int l, int r, int id = 1) {
  if (l == r) {
    seg[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, id << 1);
  build(mid + 1, r, id << 1 | 1);
  pullup(id);
}

void update(int p, int v, int l, int r, int id = 1) {
  if (p < l || p > r) return;
  if (l == r) {
    seg[id] = v;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) update(p, v, l, mid, id << 1);
  else update(p, v, mid + 1, r, id << 1 | 1);
  pullup(id);
}

const int inf = 0x3f3f3f3f;
int query(int ql, int qr, int l, int r, int id = 1) {
  if (ql > r || qr < l) return inf;
  if (ql <= l && r <= qr) return seg[id];
  int mid = (l + r) >> 1;
  return min(query(ql, qr, l, mid, id << 1), query(ql, qr, mid + 1, r, id << 1 | 1));
}

void solve()
{
  int t, n; cin >> t >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, n);
  int op, x, y;
  while (t--) {
    cin >> op >> x >> y;
    if (op == 1) {
      x++, y++;
      cout << query(x, y, 1, n) << endl;
    } else {
      x++;
      update(x, y, 1, n);
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

