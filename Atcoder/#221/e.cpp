#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

#define int ll

const int mxn = 3e5 + 5, mod = 998244353;

int a[mxn];

struct BIT {
  int n;
  vector<int> bit;
  BIT(int _n): n(_n), bit(_n + 1) {}
  inline int lowbit(int x) { return x & (-x);}
  void add(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i)) {
      bit[i] += val;
      bit[i] %= mod;
    }
  }
  int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
      ans += bit[i];
      ans %= mod;
    }
    return ans;
  }
};

int qpow(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  int cnt = 0;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  auto mp1 = mp;
  for (auto [x, y] : mp1) {
    mp[x] = ++cnt;
  }

  BIT tr(cnt);
  tr.add(mp[a[1]], (mod + 1) / 2);
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    int tmp = tr.sum(mp[a[i]]);
    ans += qpow(2, i - 1) * tmp;
    ans %= mod;
    int inv = qpow(qpow(2, i), mod - 2);
    tr.add(mp[a[i]], inv);
  }
  cout << ans << "\n";
}
  
signed main() {
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

