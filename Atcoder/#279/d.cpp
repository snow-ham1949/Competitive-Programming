#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

typedef long double ld;

ll A, B;

ld f(ll x) {
  return ld(B * x) + ld(A / sqrt(1 + x));
}

void solve()
{
  cin >> A >> B;
  ll l = 0, r = A / B + 10;
  while (r - l > 2) {
    ld a = (l * 2 + r) / 3, b = (l + r * 2) / 3;
    if (f(a) > f(b)) l = a;
    else r = b;
  }
  ld ans = A;
  for (ll i = l; i <= r; i++) {
    ans = min(ans, f(i));
  }
  cout << fixed << setprecision(10) << ans << endl;
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

