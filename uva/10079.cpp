#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define X first
#define Y second

void solve()
{
  ll n;
  while (cin >> n) {
    if (n < 0) break;
    if (n == 0) {
      cout << "1\n";
      continue;
    }
    if (n == 1) {
      cout << "2\n";
      continue;
    }
    ll ans = 2;
    for (ll i = 2; i <= n; i++) {
      ans += i;
    }
    cout << ans << "\n";
  }
}

int main() {
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

