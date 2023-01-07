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
  ll n; cin >> n;
  ll p = 0, q = 0;
  for (ll i = 2; i * i * i <= n; i++) {
    if (n % i != 0) continue;
    if ((n / i) % i == 0) {
      p = i;
      q = n / p / p;
    }
    else {
      q = i;
      p = (ll) sqrt(n / q);
    }
    break;
  }
  cout << p << " " << q << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--)
  {
    solve(); 
  }
  return 0;
}

