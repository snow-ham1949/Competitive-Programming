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
  int n; cin >> n;
  multiset<int> st;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    if (st.upper_bound(x) != st.end()) {
      st.erase(st.upper_bound(x));
    }
    st.insert(x);
  }
  cout << SZ(st) << endl;
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

