#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define ALL(v) (v).begin() (v).end()
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = (1 << 30);
const ll llinf = (1ll << 60);

const int mxn = 2000 + 5;
ll dp[mxn][mxn]; // dp[i][j] := maximum value until i choosing j element

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> a(n);
  for (ll &x : a) cin >> x;
  dp[0][0] = 0;
  dp[0][1] = -1e18;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (j == 0) dp[i][j] = 0;
      else if (j > i) dp[i][j] = -1e18;
      else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i - 1] * j);
    }
  }
  cout << dp[n][m] << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; t++)
  {
    // cout << "Case #" << t << ": ";
    solve(); 
  }
  return 0;
}

