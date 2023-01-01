#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mod = 998244353;

void solve()
{
  int n, m; cin >> n >> m;
  vector<pii> v;
  for (int i = 0, x, y; i < 3; i++) {
    cin >> x >> y;
    v.push_back({x, y});
  }

  set<pii> st;
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    st.insert({x, y});
  }

  map<pll, ll> dp;
  dp[{0, 0}] = 1;
  for (int i = 0; i < n; i++) {
    map<pll, ll> _dp;
    for (auto [pos, val] : dp) {
      auto [x, y] = pos;
      for (auto [dx, dy] : v) {
        if (st.find({x + dx, y + dy}) == st.end()) {
          _dp[{x + dx, y + dy}] += val;
          _dp[{x + dx, y + dy}] %= mod;
        }
      }
    }
    dp = _dp;
  }
  ll ans = 0;
  for (auto [pos, val] : dp) {
    ans += val;
    ans %= mod;
  }
  cout << ans << "\n";
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

