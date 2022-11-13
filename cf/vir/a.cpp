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
  string s, t; cin >> s >> t;
  ll ans = 0;
  vector<ll> a(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == t[i]) a[i] = a[i + 1];
    else if (s[i] < t[i]) a[i] = n - i;
    else a[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    ans += a[i];
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

