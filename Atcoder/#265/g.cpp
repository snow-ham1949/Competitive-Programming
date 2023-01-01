#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mxn = 1e5 + 10;

struct node {
  ll sum[3][3], cnt[3];
  node() {
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
  }
  node(int x) {
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
    cnt[x]++;
  }
  friend node operator + (node a, node b) {
    node c;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        c.sum[i][j] = a.sum[i][j] + b.sum[i][j] + a.cnt[i] * b.cnt[j];
      }
    }
    for (int i = 0; i < 3; i++) {
      c.cnt[i] = a.cnt[i] + b.cnt[i];
    }
    return c;
  }
  friend node spread(node a, int x, int y, int z) {
    node b;
    vector<int> to({x, y, z});
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        b.sum[to[i]][to[j]] += a.sum[i][j];
      }
    }
    for (int i = 0; i < 3; i++) {
      b.cnt[to[i]] += a.cnt[i];
    }
    return b;
  }
};

int n, q, a[mxn];

struct SegmentTree {
  node val[mxn << 2];
  int tag[mxn << 2][3];
  #define ls (rt << 1)
  #define rs (rt << 1 | 1)
  #define mid ((l + r) >> 1)
  void pullup(int rt) {
    val[rt] = val[ls] + val[rs];
  }
  void build(int rt, int l, int r) {
    tag[rt][0] = -1;
    if (l == r) {
      return val[rt] = a[l], void();
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pullup(rt);
  }
  void Tag(int rt, int x, int y, int z) {
    val[rt] = spread(val[rt], x, y, z);
    if (tag[rt][0] == -1) {
      tag[rt][0] = x, tag[rt][1] = y, tag[rt][2] = z;
    }
    else {
      vector<int> to({x, y, z});
      for (int i = 0; i < 3; i++) {
        tag[rt][i] = to[tag[rt][i]];
      }
    }
  }
  void pushdown(int rt) {
    if (tag[rt][0] == -1) return;
    Tag(ls, tag[rt][0], tag[rt][1], tag[rt][2]);
    Tag(rs, tag[rt][0], tag[rt][1], tag[rt][2]);
    tag[rt][0] = -1;
  }
  void update(int rt, int l, int r, int ql, int qr, int x, int y, int z) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) return Tag(rt, x, y, z);
    pushdown(rt);
    update(ls, l, mid, ql, qr, x, y, z);
    update(rs, mid + 1, r, ql, qr, x, y, z);
    pullup(rt);
  }
  node query(int rt, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return val[rt];
    pushdown(rt);
    if (ql > mid) return query(rs, mid + 1, r, ql, qr);
    if (qr <= mid) return query(ls, l, mid, ql, qr);
    return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
  }

  #undef ls
  #undef rs
  #undef mid
} t;

void solve()
{
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  t.build(1, 1, n);
  while (q--) {
    int op, l, r; cin >> op >> l >> r;
    if (op == 1) {
      node no = t.query(1, 1, n, l, r);
      ll ans = no.sum[2][1] + no.sum[2][0] + no.sum[1][0];
      cout << ans << "\n";
    }
    else {
      int x, y, z;
      cin >> x >> y >> z;
      t.update(1, 1, n, l, r, x, y, z);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  // for (int i = 1; i <= T; i++)
  while (T--)
  {
    solve(); 
  }
  return 0;
}

