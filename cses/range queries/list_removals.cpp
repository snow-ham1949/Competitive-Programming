#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mxn = 2e5 + 5;

int n, a[mxn];

int bits(int x) {
  return x == 0 ? 0 : 31 - __builtin_clz(x);
}

struct BIT {
  int bit[mxn];

  int lowbit(int x) {
    return x & (-x);
  }

  void update(int pos, int val) {
    for (int i = pos; i <= n; i += lowbit(i)) bit[i] += val;
  }

  int query(int x) {
    int p = 0;
    for (int i = 1 << bits(n); i; i >>= 1) {
      if (p + i <= n && bit[p + i] < x) {
        x -= bit[p += i];
      }
    }
    return p + 1;
  }
} bit;

void solve()
{
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    bit.update(i, 1);
  }
  int p;
  for (int i = 1; i <= n; i++) {
    cin >> p;
    int res = bit.query(p);
    cout << a[res] << " ";
    bit.update(res, -1);
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

