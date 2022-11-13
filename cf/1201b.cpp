#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 1e5 + 5;
map<int, int> mp;

void solve()
{
  int n; cin >> n;
  ll mx = 0, sum = 0;
  for (ll i = 1, x; i <= n; i++) {
    cin >> x;
    mx = max(mx, x);
    sum += x;
  }
  if (sum % 2) {
    cout << "NO\n";
  } else {
    if (mx > sum - mx) cout << "NO\n";
    else cout << "YES\n";
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

