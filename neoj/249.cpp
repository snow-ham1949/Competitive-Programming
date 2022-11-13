#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 1e5 + 5;

struct Node {
  ll sum, premax, sufmax, cmax;
  // cmax: continuous max
} seg[mxn << 2];

ll a[mxn];

void pullup(Node &cur, Node &l, Node &r) {
  cur.sum = l.sum + r.sum;
  cur.premax = max(l.premax, l.sum + r.premax);
  cur.sufmax = max(r.sufmax, l.sufmax + r.sum);
  cur.cmax = max({l.cmax, r.cmax, l.sufmax + r.premax});
}

void build(int l, int r, int id = 1) {
  if (l == r) {
    seg[id] = {a[l], a[l], a[l], a[l]};
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, id << 1);
  build(mid + 1, r, id << 1 | 1);
  pullup(seg[id], seg[id << 1], seg[id << 1 | 1]);
}

const ll inf = 5e14;
Node query(int ql, int qr, int l, int r, int id = 1) {
  if (qr < l || ql > r) return {-inf, -inf, -inf, -inf};
  if (ql <= l && r >= qr) return seg[id];
  int mid = (l + r) >> 1;
  auto nl = query(ql, qr, l, mid, id << 1);
  auto nr = query(ql, qr, mid + 1, r, id << 1 | 1);
  Node tmp;
  pullup(tmp, nl, nr);
  return tmp;
}

void solve()
{
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, n);
  cout << max(query(1, 1, 1, n).cmax, 0ll) << endl;
  //while (q--) {
  //  int l, r;
  //  cin >> l >> r;
  //  auto ans = query(l, r, 1, n);
  //  cout << max(ans.cmax, 0ll) << endl;
  //}
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

