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

void solve() {
  string s; cin >> s;
  s = "$" + s;
  if (s[1] == '1') {
    cout << "No\n";
    return;
  }
  vector<bool> v(8, false);
  v[1] = (s[7] == '1');
  v[2] = (s[4] == '1');
  v[3] = (s[2] == '1') || (s[8] == '1');
  v[4] = (s[1] == '1') || (s[5] == '1');
  v[5] = (s[3] == '1') || (s[9] == '1');
  v[6] = (s[6] == '1');
  v[7] = (s[10] == '1');
  
  FOR2(i, 7) {
    FOR1(j, i) {
      if (v[i] && v[j]) {
        for (int k = j + 1; k < i; k++) {
          if (!v[k]) {
            cout << "Yes\n";
            return;
          }
        }
      }
    }
  }
  cout << "No\n";
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

