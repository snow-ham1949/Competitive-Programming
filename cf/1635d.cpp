#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mod = 1e9 + 7;
const int mxn = 2e5 + 5;
int a[mxn];
ll pre[mxn], dp[mxn];
ll ans;

void init() {
  dp[0] = dp[1] = 1;
  pre[0] = 1, pre[1] = 2;
  for (int i = 2; i < mxn; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    pre[i] = (pre[i - 1] + dp[i]) % mod;
  }
}

void solve()
{
  int n, p; cin >> n >> p; 
  init();
  set<int> st;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    st.insert(a[i]);
  }
  
  for (int i = 0; i < n; i++) {
    int flag = 0, x = a[i];
    while (x) {
      if (x % 2) x >>= 1;
      else if (x % 4 == 0) x >>= 2;
      else break;
      if (st.find(x) != st.end()) {
        flag = 1;
        break;
      }
    }
    if (flag) continue;
    int len = __lg(a[i]) + 1;
    if (p - len >= 0) {
      ans = (ans + pre[p - len]) % mod;
    }
  }

  cout << ans << endl;
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

