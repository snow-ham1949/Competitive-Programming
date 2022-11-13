#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

void solve()
{
  int n, m; cin >> n >> m;
  multiset<int> st;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    st.insert(x);
  }
  for (int i = 0, x; i < m; i++) {
    cin >> x;
    auto it = st.upper_bound(x);
    if (it == st.begin()) {
      cout << "-1\n";
    }
    else {
      cout << *(--it) << endl;
      st.erase(it);
    }
  }
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

