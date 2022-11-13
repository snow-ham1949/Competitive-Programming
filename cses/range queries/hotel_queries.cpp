#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 2e5 + 5;
int ans;

struct Seg {
  ll seg[mxn << 2], a[mxn];

  void pullup(int id) {
    seg[id] = max(seg[id << 1] , seg[id << 1 | 1]);
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

  void bs(int l, int r, ll val, int id = 1) {
    // binary search on segment tree
    if (l == r) {
      if (seg[id] >= val) ans = l;
      seg[id] -= val;
      return;
    }
    int mid = (l + r) >> 1;
    if (seg[id << 1] >= val) bs(l, mid, val, id << 1);
    else if (seg[id << 1 | 1] >= val) bs(mid + 1, r, val, id << 1 | 1);
    pullup(id);
  }
} seg;

void solve()
{
   int n, q;
   cin >> n >> q;
   for (int i = 1; i <= n; i++) cin >> seg.a[i];
   seg.build(1, n);
   while (q--) {
    ll x; cin >> x;
    ans = 0;
    seg.bs(1, n, x);
    cout << ans << " ";
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

