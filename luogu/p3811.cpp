#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

const int mxn = 3e6 + 5;

ll inv[mxn];
ll n, p;

pll extgcd(ll a, ll b) {
  if (b == 0) return pll(1, 0);
  pll p = extgcd(b, a % b);
  return pll(p.second, p.first - p.second * (a / b));
}

void init() {
  inv[1] = 1;
  for (ll i = 2; i <= n; i++) {
    inv[i] = (p - p / i) * inv[p % i] % p;
  }
}

void solve()
{
  //ll n, p;
  cin >> n >> p;
 // for (ll i = 1; i <= n; i++) {
 //   auto [x, y] = extgcd(i, p);
 //   cout << (x + p) % p << endl;
 // }
  init();
  for (int i = 1; i <= n; i++) {
    cout << inv[i] << endl;
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

