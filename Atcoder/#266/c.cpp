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
#define FOR1(i, n) for (int i = 0; i < n; i++)
#define FOR2(i, n) for (int i = 1; i <= n; i++)
#define SZ(a) (int)(a).size()
#define X first
#define Y second

const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = (1 << 30);
const ll llinf = (1ll << 60);

pii toVec(pii a, pii b) {
  pii c = {a.X - b.X, a.Y - b.Y};
  return c;
}

int calc(pii v1, pii v2) {
  return v1.X * v2.Y - v1.Y * v2.X;
}

void solve() {
  vector<pii> v(4);
  for (int i = 0; i < 4; i++) {
    cin >> v[i].X >> v[i].Y;
  }

  if (calc(toVec(v[1], v[0]), toVec(v[3], v[0])) < 0) {
    cout << "No\n";
    return;
  }

  if (calc(toVec(v[3], v[2]), toVec(v[1], v[2])) < 0) {
    cout << "No\n";
    return;
  }

  if (calc(toVec(v[2], v[1]), toVec(v[0], v[1])) < 0) {
    cout << "No\n";
    return;
  }


  if (calc(toVec(v[0], v[3]), toVec(v[2], v[3])) < 0) {
    cout << "No\n";
    return;
  }

  cout << "Yes\n";
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

