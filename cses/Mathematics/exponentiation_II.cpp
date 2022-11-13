#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define SZ(a) (int)(a).size()
#define endl '\n'
#define X first
#define Y second

// reference:https://www.geeksforgeeks.org/find-power-power-mod-prime/

ll pow(ll a, ll b, int mod) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
void solve()
{
  const int mod = 1e9 + 7;
  ll a, b, c;
  cin >> a >> b >> c;
  cout << pow(a, pow(b, c, mod - 1), mod) << endl;
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

