#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
using namespace std;

// template<class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template<class T>
// using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define ALL(v) (v).begin() (v).end()
#define FOR1(i, n) for (int i = 0; i < n; i++)
#define FOR2(i, n) for (int i = 1; i <= n; i++)
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = (1 << 30);
const ll llinf = (1ll << 60);

const int mxn = 1e5 + 5;
int t[mxn], l[mxn];

void solve() {
  int n, L, a; cin >> n >> L >> a;
  FOR1(i, n) cin >> t[i] >> l[i];
  int st = 0, res = 0;
  FOR1(i, n) {
    res += (t[i] - st) / a;
    st = t[i] + l[i];
  }
  res += (L - st) / a;
  cout << res << "\n";
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

