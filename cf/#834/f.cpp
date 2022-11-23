#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 100 + 5;
int p[mxn];

void solve()
{
  int n, P; 
  cin >> n >> P;
  set<int> st;
  p[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    st.insert(p[i]);
  }
  int flag = 1;
  for (int i = 0; i < p[n] && flag; i++) {
    if (st.find(i) == st.end()) flag = 0;
  }
  if (flag) {
    int r = P - 1;
    while (st.find(r) != st.end()) r--;
    cout << max(0, r - p[n]) << endl;
  } else {
    int ans = P - p[n];
    for (int i = n - 1; i >= 0; i--) {
      p[i] = (p[i] + 1) % P;
      st.insert(p[i]);
      if (p[i]) break;
    }
    int r = p[n] - 1;
    while (st.find(r) != st.end()) r--;
    ans += max(0, r);
    cout << ans << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve(); 
  }
  return 0;
}

