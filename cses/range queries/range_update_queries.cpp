#include <iostream>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// range sum queries
// 1-based
struct Seg {

  static const int mxn = 2e5 + 5;

  struct Node {
    ll data, tag;
  } seg[4 * mxn];

  ll a[mxn];

  ll get_val(int l, int r, int id) {
    return (r - l + 1) * seg[id].tag + seg[id].data;
  }

  void push(int l, int r, int id) {
    seg[id].data = get_val(l, r, id);
    seg[id * 2].tag += seg[id].tag;
    seg[id * 2 + 1].tag += seg[id].tag;
    seg[id].tag = 0;
  }

  void pull(int l, int r, int id) {
    int m = (l + r) >> 1;
    seg[id].data = get_val(l, m, id * 2) + get_val(m + 1, r, id * 2 + 1);
  }

  void build(int l, int r, int id = 1) {
    if (l == r) {
      seg[id].data = a[l];
      return;
    }
    int m = (l + r) >> 1;
    build(l, m, id * 2);
    build(m + 1, r, id * 2 + 1);
    pull(l, r, id);
  }

  ll query(int ql, int qr, int l, int r, int id = 1) {
    if (qr < l || r < ql) return 0ll;
    if (ql <= l && r <= qr) return get_val(l, r, id);
    push(l, r, id);
    int m = (l + r) >> 1;
    return query(ql, qr, l, m, id * 2) + query(ql, qr, m + 1, r, id * 2 + 1);
  }

  void update(int ql, int qr, ll v, int l, int r, int id = 1) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
      seg[id].tag += v;
      return;
    }
    push(l, r, id);
    int m = (l + r) >> 1;
    update(ql, qr, v, l, m, id * 2);
    update(ql, qr, v, m + 1, r, id * 2 + 1);
    pull(l, r, id);
  }

} seg;

int n, q;

void solve()
{
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> seg.a[i];
  seg.build(1, n);
  while (q--)
  {
    int op, a, b, u;
    cin >> op;
    if (op == 1) {
      cin >> a >> b >> u;
      seg.update(a, b, (ll)u, 1, n);
    } else {
      cin >> a;
      cout << seg.query(a, a, 1, n) << endl;
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
