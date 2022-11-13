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
  vector<int> a(n);
  for (int &i : a) cin >> i;
  int ans = 0;
  for (int k = 1; k <= n; k++) {
    multiset<int> s(a.begin(), a.end());
    for (int stage = 0; stage < k; stage++) {
      auto it = s.upper_bound(k - stage);
      if (it == s.begin()) break;
      s.erase(--it);
      if (!s.empty()) {
        int x = *s.begin();
        s.erase(s.begin());
        s.insert(x + k - stage);
      }
    }
    if (SZ(s) + k == n) ans = k;
  }
  cout << ans << endl;
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

