#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

ll lowbit(int x) {
  return x & (-x);
}

class BIT {
  int n;
  vector<ll> bit;
public:
  void init(int _n) {
    n = _n;
    bit.resize(n + 1);
    for (auto &b: bit) b = 0;
  }
  ll query(ll x) const {
    ll sum = 0;
    for (; x; x -= lowbit(x)) sum += bit[x];
    return sum;
  }
  void modify(ll x, int val) {
    for (; x <= n; x += lowbit(x)) bit[x] += val;
  }
};

void solve()
{
  ll n; cin >> n;
  vector<ll> v(n);
  for (ll &i : v) cin >> i;
  BIT bit;
  bit.init(*max_element(v.begin(), v.end()));
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ans += i - bit.query(v[i] - 1);
    bit.modify(v[i], 1);
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

