#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

#define int ll

void solve()
{
  int n, p, q, r;
  cin >> n >> p >> q >> r;
  set<int> st;
  st.insert(0ll);
  int pre = 0;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    pre += x;
    st.insert(pre);
  }
  for (int x : st) {
    if (st.find(x + p) != st.end() && st.find(x + p + q) != st.end() && st.find(x + p + q + r) != st.end()) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
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

