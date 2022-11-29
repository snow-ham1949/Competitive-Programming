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
  string s, t;
  cin >> s >> t;
  int sx = 0, tx = 0;
  int ns = SZ(s), nt = SZ(t);
  for (int i = 0; i < ns; i++) {
    sx <<= 1;
    sx += (s[i] - '0');
  }
  for (int i = 0; i < nt; i++) {
    tx <<= 1;
    tx += (t[i] - '0');
  }
  int g = __gcd(sx, tx);
  if (g == 1) cout << "Love is not all you need!\n";
  else cout << "All you need is love!\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    cout << "Pair #" << i << ": ";
    solve(); 
  }
  return 0;
}

