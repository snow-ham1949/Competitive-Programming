#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

ll gen(ll x) {
  ll len = 1;
  while (x != 1) {
    if (x & 1) x = 3 * x + 1;
    else x /= 2;
    len++;
  }
  return len;
}

void solve()
{
  ll a, b; 
  while (cin >> a >> b) {
    ll l = min(a, b);
    ll r = max(a, b);
    ll max_len = -1;
    for (ll i = l; i <= r; i++) {
      max_len = max(max_len, gen(i));
    }
    cout << a << ' ' << b << ' ' << max_len << endl;
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

