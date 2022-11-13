#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 2e5 + 5;
int a[mxn];

void solve()
{
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  set<int> st;
  int l = 0, r = 0, mx = 1;
  while (r < n) {
    while (st.find(a[r]) != st.end()) {
      st.erase(a[l++]);
    }
    st.insert(a[r]);
    mx = max(mx, r - l + 1);
    r++;
  }
  cout << mx << endl;
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

