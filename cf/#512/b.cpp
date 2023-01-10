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

const int mxn = 1000 + 5;
char s[mxn][mxn], t[mxn][mxn];

bool check(int x, int y) {
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      if (i == x && j == y) continue;
      if (s[i][j] != '#') return false;
    }
  }
  return true;
}

void color(int x, int y) {
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      if (i == x && j == y) continue;
      t[i][j] = '#';
    }
  }
}

void solve() {
  int n, m; cin >> n >> m;
  FOR1(i, n) {
    FOR1(j, m) {
      cin >> s[i][j];
      t[i][j] = '.';
    }
  }

  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (check(i, j)) color(i, j);
    }
  }
  
  FOR1(i, n) {
    FOR1(j, m) {
      if (s[i][j] != t[i][j]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
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

