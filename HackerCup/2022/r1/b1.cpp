#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// #define debug

void solve()
{
  vector<pii> tree, wall;
  #define eb emplace_back
  const ll mod = 1e9 + 7;
  ll n, q;
  cin >> n;
  ll sum_xtree = 0, sum_xwall = 0;
  ll sum_ytree = 0, sum_ywall = 0;
  ll sum_sqtree = 0, sum_sqwall = 0;
  for (ll i = 0, a, b; i < n; i++)
  {
    cin >> a >> b;
    sum_xtree = (sum_xtree + a) % mod;
    sum_ytree = (sum_ytree + b) % mod;
    sum_sqtree = ((sum_sqtree + a * a % mod) % mod + b * b % mod) % mod;
  }
  cin >> q;
  for (ll i = 0, x, y; i < q; i++)
  {
    cin >> x >> y;
    sum_xwall = (sum_xwall + x) % mod;
    sum_ywall = (sum_ywall + y) % mod;
    sum_sqwall = ((sum_sqwall + x * x % mod) % mod + y * y % mod) % mod;
  }

#ifdef debug
  fprintf(stderr, "%lld %lld %lld\n%lld %lld %lld\n", sum_xtree, sum_ytree, sum_sqtree, sum_xwall, sum_ywall, sum_sqwall);
#endif
  ll ans = 0;
  ans = (n * sum_sqwall % mod + q * sum_sqtree % mod);
  ans = (ans + mod - 2ll * (sum_xtree * sum_xwall % mod) % mod) % mod;
  ans = (ans + mod - 2ll * (sum_ytree * sum_ywall % mod) % mod) % mod;
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    cout << "Case #" << i << ": ";
    solve(); 
  }
  return 0;
}


